import type { CaptchaColumn, UserColumn } from '@/db'
import DB from '@/db'
import { v4 } from 'uuid'

class UserStorage {
  sessionMap: Record<string, UserColumn> = {}
  captchaMap: Record<string, CaptchaColumn> = {}

  async login({
    name,
    password
  }: Omit<UserColumn, 'UserId'>) {
    const user = await DB.QueryUser(name)

    if (user.length === 0) {
      throw new Error('用户不存在')
    }

    if (user[0].password !== password) {
      throw new Error('密码不正确')
    }

    await DB.SetLastLoginTime(user[0].UserId)
    const session = v4()
    this.sessionMap[session] = user[0]

    return session
  }

  logout(session: string) {
    delete this.sessionMap[session]
  }

  async isLoginUserSession(session: string) {
    const res = this.sessionMap[session]

    if (!res) {
      return null
    }

    return {
      lastLoginTime: await DB.GetLastLoginTime(res.UserId),
      ...res
    }
  }

  async getCaptchaCode() {
    const recordId = v4()

    setTimeout(() => {
      delete this.captchaMap[recordId]
    }, 60000);

    this.captchaMap[recordId] = (await DB.GetRandomCaptcha())

    return {
      recordId,
      captcha: {
        image: this.captchaMap[recordId].image
      }
    }
  }

  async register({
    name,
    password,
    capthcaCode,
    captchaRecordId
  }: Omit<UserColumn, 'UserId'> & {
    capthcaCode: string
    captchaRecordId: string
  }) {

    if (this.captchaMap[captchaRecordId]?.code.toLowerCase() !== capthcaCode.toLowerCase()) {
      throw new Error('验证码不正确')
    }

    await DB.AddUser({
      UserId: v4(),
      name,
      password
    })

    return await this.login({ name, password })
  }
}

const user = new UserStorage()

export default user