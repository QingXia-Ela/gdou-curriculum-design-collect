/// <reference path="../.astro/types.d.ts" />
/// <reference types="astro/client" />


declare namespace App {
  import type { UserColumn } from "./db"
  interface Locals {
    isLogin: boolean
    user: UserColumn & { lastLoginTime: string }
  }
}