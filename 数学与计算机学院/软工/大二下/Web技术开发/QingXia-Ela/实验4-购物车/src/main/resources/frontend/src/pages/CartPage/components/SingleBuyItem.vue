<template>
  <div
    class="w-full flex items-center bg-slate-50 h-28  py-4 px-8 border-[1px]  border-b-0 last:border-b-[1px] border-black/10 rounded-sm">
    <div class="w-[8%] ">
      <t-checkbox v-model="props.item.selected" />
    </div>
    <div class="flex-1 flex h-full">
      <t-image fit="cover" class="w-40" :src="realItem.image"></t-image>
      <div class="pl-4 mt-2">
        <div class="text-[1.1rem]">{{ realItem.name }}</div>
        <div class="text-[.9rem] mt-2 text-gray-500 w-[26rem] whitespace-nowrap text-ellipsis overflow-hidden">{{
          realItem.description }}</div>
      </div>
    </div>
    <div class="w-[10%]">
      ¥ {{ realItem.price.toFixed(2) }}
    </div>
    <div class="w-[10%]">
      ¥ {{ (realItem.price * (props.item.count || 1)).toFixed(2) }}
    </div>
    <div class="w-[15%]">
      <t-input-number v-model="props.item.count" :default-value="1" :min="1" :max="10" />
    </div>
    <div class="w-[5%]">
      <t-button theme="danger" @click="$emit('delete', realItem.id)">删除</t-button>
    </div>
  </div>
</template>

<script setup>
import { computed } from 'vue';

const props = defineProps(['item'])

const realItem = computed(() => props.item.item)
</script>