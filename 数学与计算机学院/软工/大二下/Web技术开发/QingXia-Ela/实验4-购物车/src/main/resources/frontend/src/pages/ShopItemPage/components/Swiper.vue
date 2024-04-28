<template>
  <t-swiper class="h-full overflow-hidden" :duration="300" :interval="2000" :navigation="{ size: 'large' }">
    <t-swiper-item v-for="item in images" :key="item">
      <t-image :src="item" class="h-full"></t-image>
    </t-swiper-item>
  </t-swiper>
</template>

<script setup>
import { computed } from 'vue'

const props = defineProps(['images'])

const images = computed(() => props.images.map(i => i.url))
</script>