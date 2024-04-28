<template>
  <div class="w-full z-50 fixed left-0 bottom-0 h-18 py-4 px-16 border-[1px] bg-white flex justify-between">
    <span class="font-bold text-[1.2rem] text-red-500">合计：¥ {{ sum.toFixed(2) }}</span>
    <t-button theme="primary" size="large" @click="$emit('buy')">结算</t-button>
  </div>
</template>

<script setup>
import { computed } from 'vue';

const props = defineProps(['items'])

const sum = computed(() => {
  let s = 0

  props.items.forEach(({
    item,
    count,
    selected
  }) => {
    if (selected) {
      s += item.price * count
    }
  })

  return s
})
</script>