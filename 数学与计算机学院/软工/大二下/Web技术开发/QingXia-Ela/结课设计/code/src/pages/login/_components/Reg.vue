<script setup lang="ts">
import { onMounted, ref } from 'vue';
import { Input, Form, FormItem, Button } from 'tdesign-vue-next'
import { api_get_captcha } from '../_api';

const account = ref();
const password = ref();
const capthcaCode = ref();
let captchaRecordId = "";

const captchaImg = ref();

const setCaptcha = () => {
  api_get_captcha().then(({
    data: {
      recordId,
      captcha: {
        image
      }
    } }) => {
    captchaRecordId = recordId
    captchaImg.value.src = `data:image/png;base64,${image}`
  })
}

onMounted(() => {
  setCaptcha()
})
</script>

<template>
  <h1 class="pb-12">注册</h1>
  <Form colon label-align="left">
    <FormItem label="账号">
      <Input v-model="account" placeholder="请输入账号" />
    </FormItem>
    <FormItem label="密码">
      <Input v-model="password" type="password" placeholder="请输入密码" />
    </FormItem>
    <FormItem label="验证码">
      <Input v-model="capthcaCode" placeholder="请输入验证码" />
      <div class="ml-4 w-20">
        <img ref="captchaImg" class="h-8" src="" alt="" />
      </div>
    </FormItem>
  </Form>
  <div class="w-full mt-8 flex flex-col gap-3">
    <Button class="w-full" @click="$emit('reg', { name: account, password, capthcaCode, captchaRecordId })">注册</Button>
    <Button class="w-full" variant="outline" @click="$emit('log')">返回登录</Button>
  </div>
</template>