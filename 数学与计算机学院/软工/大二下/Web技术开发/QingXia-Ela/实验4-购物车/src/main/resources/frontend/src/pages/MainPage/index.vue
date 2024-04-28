<template>
  <div class="w-full">
    <ModuleTitle>产品推荐</ModuleTitle>
    <RecommandItem v-for="{ item, want, desc } in items.slice(0, 6)" :key="item.id" :item="item" :want="want"
      :desc="desc" />
    <div class="w-full flex justify-center items-center mt-2">
      <router-link to="/all">
        <div class="blackbutton">查看所有商品</div>
      </router-link>
    </div>
  </div>
</template>

<script setup>
import RecommandItem from "./components/RecommandItem.vue";
import ModuleTitle from "./components/ModuleTitle.vue";
import { onMounted, ref } from "vue";
import { Recommend } from "./api";

const items = ref([])

onMounted(() => {
  Recommend().then((res) => {
    items.value = res
  })
})
</script>

<style scoped>
.blackbutton {
  border: none;
  /* height: 44px;
  min-width: 80px; */
  border-radius: 2px;
  background: #697880;
  color: #fff;
  font-weight: bold;
  padding: 15px 25px;
  transition: background-color 0.1s;
}

.blackbutton:hover {
  background: #424b50;
  color: #fff;
}
</style>