import { createRouter, createWebHistory } from "vue-router";

const routes = [
  {
    path: '/',
    name: 'Home',
    component: () => import('../pages/MainPage/index.vue')
  },
  {
    path: '/all',
    name: 'All',
    component: () => import('../pages/ViewAllPage/index.vue')
  },
  {
    path: '/cart',
    name: 'Cart',
    component: () => import('../pages/CartPage/index.vue')
  },
  {
    path: '/item/:id',
    name: 'Item',
    component: () => import('../pages/ShopItemPage/index.vue')
  }
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

router.afterEach(() => {
  window.scrollTo(0, 0)
})


export default router