import mysql from 'mysql'

const connection = mysql.createConnection({
  host: import.meta.env.DB_HOST,
  user: import.meta.env.DB_USER,
  password: import.meta.env.DB_PASSWORD,
  database: import.meta.env.DB_DATABASE
})

connection.connect((error) => {
  if (!error) {
    console.log('数据库连接成功');
    return
  }
  console.log(error);
  process.exit(1)
})

process.on('exit', () => {
  console.log('数据库连接已断开');
  connection.end()
})

export interface UserColumn {
  UserId: string
  name: string
  password: string
}

export interface LastLoginColumn {
  UserId: string
  lastLoginTime: string
}

export interface CaptchaColumn {
  idcaptcha: number
  code: string
  /** base64 */
  image: string
}

function queryHook(option: string, callback?: (result: any) => any) {
  return (resolve: Function, reject: Function) => {
    connection.query(option, (error, result) => {
      if (error) reject(error)

      resolve(callback ? callback(result) : result)
    })
  }
}

const DB_NAME = import.meta.env.DB_DATABASE

class DB {
  static connection = connection
  static AddUser({
    UserId,
    name,
    password
  }: UserColumn) {
    return new Promise<unknown>(queryHook(`INSERT INTO ${DB_NAME}.user (UserId, name, password) VALUES ('${UserId}', '${name}', '${password}')`, () => ({
      UserId,
      name,
      password
    })))
  }

  static QueryUser(name: string) {
    return new Promise<UserColumn[]>(queryHook(`SELECT * FROM ${DB_NAME}.user WHERE name = '${name}'`))
  }

  static SetLastLoginTime(UserId: string) {
    const time = new Date().toLocaleString()

    return new Promise<LastLoginColumn>(queryHook(`INSERT INTO ${DB_NAME}.lastLogin (UserId, lastLoginTime) VALUES ('${UserId}', '${time}') ON DUPLICATE KEY UPDATE lastLoginTime = '${time}'`))
  }

  static GetLastLoginTime(UserId: string) {
    return new Promise<LastLoginColumn>(queryHook(`SELECT * FROM ${DB_NAME}.lastLogin WHERE UserId = '${UserId}'`, (res) => res[0]))
  }

  static GetRandomCaptcha() {
    return new Promise<CaptchaColumn>(queryHook(`SELECT * FROM ${DB_NAME}.captcha ORDER BY RAND() LIMIT 1`, (res) => res[0]))
  }
}

/**
 * Simulate DB
 */
class DBTest {
  private static Users: UserColumn[] = [
    {
      UserId: '61a629fa-62ce-4150-a037-047ccbd5ea27',
      name: 'test',
      password: 'test'
    }
  ]
  private static LastLogin: LastLoginColumn[] = []
  private static Captcha: CaptchaColumn[] = [
    {
      idcaptcha: 1,
      code: "7364",
      image: `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`
    }
  ]
  static AddUser({
    UserId,
    name,
    password
  }: UserColumn) {
    return new Promise<UserColumn>((resolve, reject) => {
      const user = {
        UserId, name, password
      }
      if (this.Users.find(user => user.name === name)) {
        reject(new Error('用户已存在'))
        return
      }
      this.Users.push(user)
      resolve(user)
    })
  }

  static QueryUser(name: string) {
    return new Promise<UserColumn[]>((resolve, reject) => {
      const user = this.Users.find(user => user.name === name)
      resolve(user ? [user] : [])
    })
  }

  static GetRandomCaptcha() {
    return new Promise<CaptchaColumn>((resolve, reject) => {
      const captcha = this.Captcha[Math.floor(Math.random() * this.Captcha.length)]
      resolve(captcha)
    })
  }

  static SetLastLoginTime(UserId: string) {
    return new Promise<LastLoginColumn>((resolve, reject) => {
      const user = this.LastLogin.find(user => user.UserId === UserId)
      const lastLoginTime = new Date().toLocaleString()
      if (!user) {
        const data = {
          UserId,
          lastLoginTime,
        }
        this.LastLogin.push(data)
        resolve(data)
      }
      else {
        user.lastLoginTime = lastLoginTime
        resolve(user)
      }
    })
  }

  static GetLastLoginTime(UserId: string) {
    return new Promise<LastLoginColumn>((resolve, reject) => {
      const user = this.LastLogin.find(user => user.UserId === UserId)
      if (!user) {
        reject(new Error('User not found'))
        return
      }
      resolve(user)
    })
  }
}

export default DBTest