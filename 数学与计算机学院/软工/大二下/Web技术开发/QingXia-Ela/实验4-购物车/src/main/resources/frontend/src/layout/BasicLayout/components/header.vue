<template>
  <div class="w-full fixed top-0 left-0 z-[999]">
    <t-head-menu v-model="currentSelect" class="w-full !px-20 shadow-md">
      <template #logo>
        <img :src="LeftLogo" class="h-8">
      </template>
      <t-menu-item value="home" to="/">
        主页
      </t-menu-item>
      <t-menu-item value="all" to="/all">
        商品列表
      </t-menu-item>
      <template #operations>
        <router-link to="/cart" @click="currentSelect = 'cart'">
          <t-button>
            我的购物车
            <i class="pl-2 flex justify-center items-center">
              <CartIcon />
            </i>
          </t-button>
        </router-link>
      </template>
    </t-head-menu>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { CartIcon } from "tdesign-icons-vue-next";
import LeftLogo from '../assets/left_logo.webp'

const currentSelect = ref()
</script>
