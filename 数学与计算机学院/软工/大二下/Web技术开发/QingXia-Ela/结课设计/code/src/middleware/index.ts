import { LOGIN_SESSION } from "@/constants";
import user from "@/store/user";
import { defineMiddleware } from "astro:middleware";

// `context` 和 `next` 会自动被类型化
export const onRequest = defineMiddleware(async (context, next) => {
  context.locals.isLogin = false
  const session = context.cookies.get(LOGIN_SESSION)?.value

  if (session) {
    const info = await user.isLoginUserSession(session)
    if (info) {
      context.locals.isLogin = true
      context.locals.user = info
    }
    else {
      context.cookies.delete(LOGIN_SESSION)
    }
  }

  return next();
});
