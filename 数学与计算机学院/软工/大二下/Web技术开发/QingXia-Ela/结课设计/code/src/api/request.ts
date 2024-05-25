import { MessagePlugin } from 'tdesign-vue-next';

export default async function request(url: string, options?: RequestInit) {
  const headers: Record<string, string> = {
    "Content-Type": "application/json",
    "Accept": "application/json",
  }

  if (options?.body) {
    headers['Content-Length'] = `${(options.body as string).length}`
  }
  const res = await fetch(url, {
    headers,
    ...options
  });

  if (res.status !== 200) {
    MessagePlugin.error((await res.json()).msg);
    return
  }
  return await res.json();
}