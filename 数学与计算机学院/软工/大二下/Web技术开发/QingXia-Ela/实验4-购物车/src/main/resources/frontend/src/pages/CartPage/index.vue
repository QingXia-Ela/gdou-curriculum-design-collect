<template>
  <template v-if="!showEmpty">
    <div class="text-2xl font-bold text-center my-8">
      购物车结算
    </div>
    <TopOperate v-model="selectAll" />
    <SingleBuyItem v-for="item in itemList" :item="item" @delete="onDelete" />
    <BottomSum @buy="onBuy" :items="itemList" />
  </template>
  <div v-else class="text-2xl font-bold h-[60vh] flex justify-center items-center backdrop-blur-sm my-8">啥都没有哦，
    <router-link class="text-blue-700 underline" to="/all">去看看所有商品</router-link>
  </div>
  <t-dialog v-model:visible="visible" header="确认删除" :on-confirm="ConfirmDelete">
    <p>确认删除商品吗</p>
  </t-dialog>
</template>

<script setup>
import SingleBuyItem from './components/SingleBuyItem.vue'
import TopOperate from './components/TopOperate.vue'
import BottomSum from './components/BottomSum.vue'
import { computed, nextTick, onMounted, ref, watch } from 'vue';
import { Shopcart_Status, Shopcart_Modify, Shopcart_Checkout } from './api'
import throttle from 'lodash/throttle'
import { NotifyPlugin } from 'tdesign-vue-next';

/**
 * @type {{
 *  item: import("../../assets/items.json")[0]
 *  count: number
 *  selected: boolean
 * }[]}
 */
const itemList = ref([])
const selectAll = ref(false)
const showEmpty = ref(true)
const visible = ref(false)
let deleteId = -1

const syncInfo = throttle(() => {
  Shopcart_Modify(itemList.value.map(({ item, ...rest }) => ({ id: item.id, ...rest })))
}, 500)

watch(selectAll, () => {
  if (selectAll.value)
    itemList.value.forEach(item => {
      item.selected = selectAll.value
    })
})

watch(itemList, () => {
  selectAll.value = itemList.value.every(item => item.selected)
  if (itemList.value.length == 0) { showEmpty.value = true }
  syncInfo()
}, { deep: true })

async function onBuy() {
  await Shopcart_Modify(itemList.value.map(({ item, ...rest }) => ({ id: item.id, ...rest })))
  const money = Number(await Shopcart_Checkout()).toFixed(2)
  NotifyPlugin.success({
    title: '成功',
    content: `结算成功，总金额为¥ ${money}元`,
  })
  itemList.value = []
}

async function onDelete(id) {
  deleteId = id
  visible.value = true
}

async function ConfirmDelete() {
  try {
    itemList.value = itemList.value.filter(({ item }) => item.id != deleteId)
    await Shopcart_Modify(itemList.value.map(({ item, ...rest }) => ({ id: item.id, ...rest })).filter(({ id }) => id != deleteId))
    NotifyPlugin.success({
      title: '成功',
      content: '删除成功',
    })
  } catch (e) {
    NotifyPlugin.error({
      title: '错误',
      content: '删除失败',
    })
  } finally {
    visible.value = false
  }
}

onMounted(() => {
  Shopcart_Status().then(res => {
    itemList.value = res
    nextTick(() => {
      showEmpty.value = itemList.value.length == 0
    })
  })
})
</script>

<style scoped></style>