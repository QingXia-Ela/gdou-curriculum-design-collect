<template>
  <div class="w-full bg-black/3 p-4 backdrop-blur-md">
    <div class="text-2xl text-center font-bold my-4 mb-10">商品/产品一览</div>
    <BriefItem v-for="item in items" :key="item.id" :item="item" />
  </div>
</template>

<script setup>
import { onMounted, ref } from 'vue';
import BriefItem from './components/BriefItem.vue'
import { ViewAll } from './api'

const items = ref([])

onMounted(() => {
  ViewAll().then(res => {
    items.value = res
  })
})
</script>
