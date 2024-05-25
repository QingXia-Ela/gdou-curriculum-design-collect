import request from "@/api/request"
import type { UserColumn } from "@/db"

export const api_login = ({
  name,
  password
}: Omit<UserColumn, 'UserId'>) => {
  return request(`/api/login`, {
    method: "POST",
    body: JSON.stringify({
      name,
      password
    })
  })
}

export const api_register = (data: Record<string, string>) => {
  return request(`/api/register`, {
    method: "POST",
    body: JSON.stringify(data)
  })
}

export const api_get_captcha = () => {
  return request(`/api/getCaptcha`)
}

export const api_logout = () => {
  return request(`/api/logout`)
}