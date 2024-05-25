<script setup lang="ts">
import { ref } from 'vue';
import { Input, Form, FormItem, Button } from 'tdesign-vue-next'

const account = ref();
const password = ref();
</script>

<template>
  <h1 class="pb-12">登录</h1>
  <Form colon label-align="left">
    <FormItem label="账号">
      <Input v-model="account" placeholder="请输入账号" />
    </FormItem>
    <FormItem label="密码">
      <Input v-model="password" type="password" placeholder="请输入密码" />
    </FormItem>
  </Form>
  <div class="w-full mt-8 flex flex-col gap-3">
    <Button class="w-full" @click="$emit('log', { account, password })">登录</Button>
    <Button class="w-full" variant="outline" @click="$emit('reg')">注册账号</Button>
  </div>
</template>