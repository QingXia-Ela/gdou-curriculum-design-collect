import merge from 'lodash/merge'

const DEFAULT_OPTIONS = {
  method: 'GET',
  headers: {
    'Content-Type': 'application/json',
  },
}

const ROOT = 'http://localhost:8080/api'

const sleep = (time) => new Promise((resolve) => setTimeout(resolve, time))

export default async function request(url, options = {}) {
  const finalOptions = merge({}, DEFAULT_OPTIONS, options)
  const res = await fetch(ROOT + url, options).then((res) => res.json())
  await sleep(300)
  return res
}