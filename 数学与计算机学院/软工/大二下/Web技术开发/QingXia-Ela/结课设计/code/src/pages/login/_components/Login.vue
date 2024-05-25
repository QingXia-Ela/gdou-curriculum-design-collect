<script setup lang="ts">
import { ref } from 'vue';
import Log from './Log.vue'
import Reg from './Reg.vue'
import { api_login, api_register } from '../_api';
import { LOGIN_SESSION } from '@/constants';
import { MessagePlugin } from 'tdesign-vue-next';

const isReg = ref(false);

const checkObj = (obj: Record<string, string>) => {
  return Object.keys(obj).every(key => !!obj[key])
}

const onLog = (data: Record<string, string>) => {
  if (!checkObj(data)) {
    MessagePlugin.warning('账号或密码不能为空')
    return
  }
  const {
    account,
    password
  } = data
  api_login({
    name: account,
    password
  }).then(({ data: { session } }) => {
    document.cookie = `${LOGIN_SESSION}=${session}`
    MessagePlugin.success('登录成功，即将跳转至首页')
    setTimeout(() => {
      window.location.href = '/'
    }, 1000);
  })
}

const onReg = (data: Record<string, string>) => {
  if (!checkObj(data)) {
    MessagePlugin.warning('账号或密码不能为空')
    return
  }

  api_register(data).then(({ data: { session } }) => {
    document.cookie = `${LOGIN_SESSION}=${session}`
    MessagePlugin.success('注册成功，即将跳转至登录界面')
    setTimeout(() => {
      window.location.href = '/login'
    }, 1000);
  })
}
</script>

<template>
  <div class="w-full p-20 flex justify-center items-center">
    <div class="w-[480px] bg-white/80 backdrop-blur-sm rounded-md p-8 flex flex-col">
      <Log v-if="!isReg" @reg="isReg = true" @log="onLog" />
      <Reg v-else @log="isReg = false" @reg="onReg" />
    </div>
  </div>
</template>