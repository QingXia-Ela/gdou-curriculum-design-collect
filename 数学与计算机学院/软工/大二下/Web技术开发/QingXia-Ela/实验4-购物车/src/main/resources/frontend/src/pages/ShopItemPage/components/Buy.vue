<template>
  <div class="w-full bg py-6 px-10 h-30">
    <div class="text-[1.4rem]">购买 {{ props.item.name }}</div>
    <div class="flex justify-end mt-6">
      <div class="wrapper bg-black flex items-center rounded-[3px]">
        <span class="px-4 py-2 text-white">¥ {{ props.item.price }}</span>
        <t-button theme="success" size="large" :disabled="props.adding || props.include" @click="$emit('buy')"
          :loading="props.adding">
          {{ props.include ? "已在购物车中" : "添加至购物车" }}</t-button>
      </div>
    </div>
  </div>
</template>

<script setup>
const props = defineProps(['item', 'adding', 'include'])
</script>

<style scoped>
.bg {
  background: linear-gradient(60deg, rgba(255, 255, 255, 0.3) 5%, rgba(3, 126, 249, 0.3) 95%);
}
</style>