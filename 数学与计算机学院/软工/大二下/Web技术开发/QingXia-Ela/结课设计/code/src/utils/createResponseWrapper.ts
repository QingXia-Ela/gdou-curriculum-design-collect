export default function createResponseWrapper<T>(status: number, msg: string, data?: T) {
  return {
    status,
    msg,
    data
  }
}