<script setup lang="ts">
import { Swiper, SwiperItem } from 'tdesign-vue-next';

const props = defineProps<{
  datas: Array<{
    img: string
    href: string
  }>
}>()
</script>

<template>
  <div class="w-full h-full">
    <Swiper class="w-full h-full">
      <SwiperItem v-for="data in props.datas" :key="data.href">
        <a target="_blank" :href="data.href">
          <img :src="data.img" class="w-full h-full object-contain" />
        </a>
      </SwiperItem>
    </Swiper>
  </div>
</template>