import user from "@/store/user"
import createResponseWrapper from "@/utils/createResponseWrapper"

export async function GET() {
  const captcha = await user.getCaptchaCode()
  return new Response(JSON.stringify(
    createResponseWrapper(
      200,
      'success',
      captcha
    )
  ))
}