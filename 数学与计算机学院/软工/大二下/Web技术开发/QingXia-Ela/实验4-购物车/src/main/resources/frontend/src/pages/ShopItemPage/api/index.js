/** 根据 ID 查询商品 `/shopitem/:id` */
import request from "../../../api/request.js";

export const ShopItem_ID = (id) => request(`/shopitem/${id}`);

/** 当前商品是否在购物车内 `/shopcart/include/:id` */

export const ShopItem_Include = (id) => request(`/shopcart/include/${id}`);

/** 购物车状态 `/shopcart/status` */
export const Shopcart_Status = () => {
  return request('/shopcart/status')
}

/** 添加到购物车 post `/shopcart/add` */

export const ShopCart_Add = (id) => request(`/shopcart/add`, {
  method: 'POST',
  body: id
});