<template>
  <div class="w-full flex items-center bg-slate-50 h-18 py-4 px-8 border-[1px] border-black/10 rounded-sm mb-1">
    <div class="w-[8%] ">
      <t-checkbox v-model="selectAll" />全选
    </div>
    <div class="flex-1 flex">
      商品详情
    </div>
    <div class="w-[10%]">
      单价
    </div>
    <div class="w-[10%]">
      小计
    </div>
    <div class="w-[15%]">
      数量
    </div>
    <div class="w-[5%]">
      操作
    </div>
  </div>
</template>

<script setup>
const selectAll = defineModel()
</script>