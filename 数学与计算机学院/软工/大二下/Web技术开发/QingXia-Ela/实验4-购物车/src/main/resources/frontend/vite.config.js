import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'
import AutoImport from 'unplugin-auto-import/vite';
import Components from 'unplugin-vue-components/vite';
import { TDesignResolver, ElementPlusResolver } from 'unplugin-vue-components/resolvers';

// https://vitejs.dev/config/
export default defineConfig({
  build: {
    outDir: "../static"
  },
  plugins: [
    vue(),
    AutoImport({
      resolvers: [TDesignResolver({
        library: 'vue-next'
      }), ElementPlusResolver()],
    }),
    Components({
      resolvers: [TDesignResolver({
        library: 'vue-next'
      }), ElementPlusResolver()],
    }),
  ],
})
