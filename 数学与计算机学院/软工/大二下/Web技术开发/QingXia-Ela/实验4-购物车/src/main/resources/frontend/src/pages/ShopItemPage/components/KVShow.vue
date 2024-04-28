<template>
  <div class="flex w-full text-[.8rem] my-2">
    <div class="w-1/3 text-gray-600">{{ props.keyText }}</div>
    <span class="w-2/3 ">
      <slot />
    </span>
  </div>
</template>


<script setup>
const props = defineProps(['key-text'])
</script>