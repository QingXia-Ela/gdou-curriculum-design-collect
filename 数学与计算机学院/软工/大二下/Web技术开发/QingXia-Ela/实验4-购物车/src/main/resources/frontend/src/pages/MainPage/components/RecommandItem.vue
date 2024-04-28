<template>
  <div class="text-black px-6 py-4 backdrop-blur-md bg-black/5 rounded-md mb-4 last:mb-0">
    <div class="text-2xl">
      {{ props.item.name }}
    </div>
    <div class="text-[12px] mt-2" v-if="props.want">
      <span class="text-gray-600 mr-1">{{ props.desc || "因为您想要" }}</span>
      <router-link :to="`/item/${props.want.id}`" class="hover:underline hover:text-blue-500">
        {{ props.want.name }}
      </router-link>
    </div>
    <div class="flex w-full p-4 !bg-transparent gap-5 mt-2">
      <t-image fit="cover" class="flex-1 h-52 " v-for="image in props.item.images.slice(0, 3)" :key="image.url"
        :src="image.url"></t-image>
    </div>
    <div class="w-full flex justify-end">
      <router-link :to="`/item/${props.item.id}`">
        <t-button>访问产品页面</t-button>
      </router-link>
    </div>
  </div>
</template>

<script setup>
const props = defineProps(['item', 'want', 'desc'])
</script>
