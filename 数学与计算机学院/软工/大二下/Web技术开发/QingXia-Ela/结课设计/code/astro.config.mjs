import { defineConfig } from 'astro/config';
import node from '@astrojs/node';
import vue from '@astrojs/vue';
import tailwind from '@astrojs/tailwind';

export default defineConfig({
  integrations: [vue(), tailwind({
    applyBaseStyles: false
  })],
  output: 'server',
  adapter: node({
    mode: 'standalone',
  }),
  vite: {
    resolve: {
      alias: {
        '@': '/src',
      },
    }
  },
});