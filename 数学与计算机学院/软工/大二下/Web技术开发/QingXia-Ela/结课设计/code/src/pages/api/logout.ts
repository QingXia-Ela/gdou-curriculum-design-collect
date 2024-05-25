import { LOGIN_SESSION } from "@/constants";
import user from "@/store/user";
import createResponseWrapper from "@/utils/createResponseWrapper";
import type { APIContext } from "astro";

export async function GET({
  cookies
}: APIContext) {
  const session = cookies.get(LOGIN_SESSION)?.value
  if (session) {
    user.logout(session)
    cookies.delete(LOGIN_SESSION)
    return new Response(JSON.stringify(
      createResponseWrapper(
        200,
        'success',
      )
    ))
  }

  return new Response(JSON.stringify(
    createResponseWrapper(
      401,
      'unauthorized',
    )
  ))
}