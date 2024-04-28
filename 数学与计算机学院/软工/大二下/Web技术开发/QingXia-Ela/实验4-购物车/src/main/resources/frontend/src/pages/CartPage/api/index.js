/** 修改购物车物品内容 post `/shopcart/modify` */
import request from "../../../api/request.js";

export const Shopcart_Status = () => {
  return request('/shopcart/status')
}

export const Shopcart_Modify = (data) => {
  return request('/shopcart/modify', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify(data),
  })
}
/** 结算 `/shopcart/checkout` */

export const Shopcart_Checkout = () => {
  return request('/shopcart/checkout')
}