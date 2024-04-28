<script setup>
import BasicLayout from './layout/BasicLayout/index.vue'
</script>

<template>
  <BasicLayout />
  <div id="bg"></div>
</template>

<style scoped>
#bg {
  position: fixed;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  z-index: -1;
  background-image: url(https://nanyanostore.com/cdn/shop/files/tunagiPC_1296x.png?v=1639728452);
  background-origin: content-box;
  background-repeat: no-repeat;
  background-size: contain;
  opacity: .3;
}
</style>
