<template>
  <Header></Header>
  <div class="w-full min-h-[100vh] px-36 pt-20 pb-10">
    <router-view></router-view>
  </div>
  <Footer></Footer>
</template>

<script setup>

import Header from "./components/header.vue";
import Footer from "./components/footer.vue";
</script>

<style scoped></style>