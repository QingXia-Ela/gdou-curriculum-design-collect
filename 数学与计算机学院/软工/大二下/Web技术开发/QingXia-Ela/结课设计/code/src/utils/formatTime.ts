export default function formatTime(time: Date, formatStr: string) {
  const date = new Date(time)
  const year = date.getFullYear()
  const month = date.getMonth() + 1
  const day = date.getDate()
  const hour = date.getHours()
  const minute = date.getMinutes()
  const second = date.getSeconds()

  return formatStr
    .replace(/yyyy/g, year.toString())
    .replace(/MM/g, month.toString().padStart(2, '0'))
    .replace(/dd/g, day.toString().padStart(2, '0'))
    .replace(/HH/g, hour.toString().padStart(2, '0'))
    .replace(/mm/g, minute.toString().padStart(2, '0'))
    .replace(/ss/g, second.toString().padStart(2, '0'))
}