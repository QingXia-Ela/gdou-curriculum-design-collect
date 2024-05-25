import { LOGIN_SESSION } from "@/constants";
import user from "@/store/user";
import createErrorResponse from "@/utils/createErrorResponse";
import createResponseWrapper from "@/utils/createResponseWrapper";
import type { APIContext } from "astro";

export async function POST({
  cookies,
  request
}: APIContext) {
  try {
    const body = await request.json();

    const session = await user.register(body)

    cookies.set(LOGIN_SESSION, session, { maxAge: 60 * 60 * 24 * 7 })

    return new Response(JSON.stringify(
      createResponseWrapper(
        200,
        'success',
        {
          session
        }
      )
    ))
  } catch (e: any) {
    return createErrorResponse(e)
  }
}