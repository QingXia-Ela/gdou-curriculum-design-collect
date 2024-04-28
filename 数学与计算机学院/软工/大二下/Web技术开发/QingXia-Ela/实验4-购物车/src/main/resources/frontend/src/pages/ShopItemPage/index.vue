<template>
  <div class="w-full px-6 pt-4 pb-8 backdrop-blur-sm rounded-md bg-black/5" v-if="!loading">
    <div class="text-[1.8rem]">{{ item.name }}</div>
    <div class="info flex justify-between gap-3 mt-6">
      <div class="swiper flex-1">
        <Swiper :images="item.images" />
      </div>
      <div class="w-[28%]">
        <t-image fit="cover" :src="item.image" class="h-36"></t-image>
        <span class="text-gray-700 text-[.86rem]"> {{ item.description }}</span>
        <div class="mt-6 w-full">
          <KVShow key-text="发行日期">
            {{ item.date }}
          </KVShow>
          <br />
          <KVShow class="text-blue-700" v-if="item.developer" key-text="开发商">
            {{ item.developer }}
          </KVShow>
          <KVShow class="text-blue-700" v-if="item.publisher" key-text="发行商">
            {{ item.publisher }}
          </KVShow>
        </div>
        <br />
        <div class="tag w-full">
          <span class="text-[.9rem]">该产品包含标签如下：</span>
          <div class="flex flex-wrap gap-1 mt-2">
            <t-tag v-for="tag in item.tags" :key="tag" theme="primary" variant="outline">{{ tag }}</t-tag>
          </div>
        </div>
      </div>
    </div>
    <div class="mt-6">
      <Buy @buy="addCart(item.id)" :item="item" :include="include" :adding="addingCart" />
    </div>
  </div>
  <div v-else class="w-full bg-black/10 p-6 text-center text-[1.2rem] font-bold rounded-md">加载中...</div>
</template>

<script setup>
import KVShow from './components/KVShow.vue'
import Swiper from './components/Swiper.vue'
import Buy from './components/Buy.vue'
import { onMounted, ref } from 'vue';
import { ShopItem_ID, ShopCart_Add, ShopItem_Include } from './api'
import { useRoute } from 'vue-router';
import { NotifyPlugin } from 'tdesign-vue-next';

const item = ref({})

const route = useRoute()

const loading = ref(true)

const include = ref(false)

const addingCart = ref(false)

async function addCart(id) {
  addingCart.value = true
  try {
    await ShopCart_Add(id)
    NotifyPlugin.success({
      title: '成功',
      content: '商品添加成功',
    })
    include.value = true
  } catch (e) {
    NotifyPlugin.error({
      title: '错误',
      content: '商品添加失败，稍后再试试吧',
    })
  } finally {
    addingCart.value = false
  }
}

onMounted(() => {
  ShopItem_ID(route.params.id).then(res => {
    item.value = res
    loading.value = false
  })
  ShopItem_Include(route.params.id).then(res => {
    include.value = res
  }).catch(() => {
    include.value = false
  })
})
</script>

<style scoped></style>