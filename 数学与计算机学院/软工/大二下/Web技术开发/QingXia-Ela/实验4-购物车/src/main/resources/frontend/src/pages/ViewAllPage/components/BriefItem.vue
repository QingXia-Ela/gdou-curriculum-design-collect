<template>
  <router-link :to="`/item/${props.item.id}`">
    <div class="w-full my-4 flex bg-black/5 hover:bg-black/10 transition-colors h-36 box-wrapper rounded-md">
      <t-image class="w-1/4" :src="props.item.image" fit="cover"></t-image>
      <div class="w-3/4 flex justify-between info-box py-2 px-4">
        <div class="left-info flex-1 flex flex-col justify-between">
          <div class="text-[1.2rem]">{{ props.item.name }}</div>
          <div class="max-w-[70%] text-[0.7rem] text-gray-600">{{ props.item.description }}</div>
          <div class="text-[0.84rem]">{{ props.item.tags.join(", ") }}</div>
        </div>
        <div class="right-price w-1/5 flex justify-end items-center">
          <div class="text-[1.2rem]">¥ {{ props.item.price.toFixed(2) }}</div>
        </div>
      </div>
    </div>
  </router-link>
</template>

<script setup>
/**
 * @type {{
 *   item: import("../../../assets/items.json")[0]
 * }}
 */
const props = defineProps(['item'])
</script>
