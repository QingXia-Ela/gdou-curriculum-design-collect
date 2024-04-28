package com.lab4.db;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.lab4.Utils;

public class Database {
    private static final String categoryJsonStr = "[\n" +
            "  {\n" +
            "    \"id\": 0,\n" +
            "    \"name\": \"Left 会社 - 白色相簿专栏展示\",\n" +
            "    \"background\": \"\",\n" +
            "    \"items\": [\n" +
            "      0\n" +
            "    ]\n" +
            "  },\n" +
            "  {\n" +
            "    \"id\": 2,\n" +
            "    \"name\": \"极限竞速 - 地平线专区\",\n" +
            "    \"background\": \"\",\n" +
            "    \"items\": [\n" +
            "      100,\n" +
            "      101\n" +
            "    ]\n" +
            "  },\n" +
            "  {\n" +
            "    \"id\": 3,\n" +
            "    \"name\": \"Yuzusoft专区\",\n" +
            "    \"background\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/2510810/page_bg_generated_v6b.jpg\",\n" +
            "    \"items\": [\n" +
            "      1000,\n" +
            "      1001,\n" +
            "      1002\n" +
            "    ]\n" +
            "  },\n" +
            "  {\n" +
            "    \"id\": 1919810,\n" +
            "    \"name\": \"命运2专区\",\n" +
            "    \"background\": \"\",\n" +
            "    \"items\": [\n" +
            "      114514\n" +
            "    ]\n" +
            "  }\n" +
            "]";

    private static final String ItemsJsonStr = "[\n" +
            "  {\n" +
            "    \"id\": 0,\n" +
            "    \"categoryId\": 0,\n" +
            "    \"name\": \"白色相簿：编缀的冬日回忆\",\n" +
            "    \"price\": 108,\n" +
            "    \"description\": \"由AQUAPLUS呈献，在日本拥有顶级人气的恋爱冒险游戏系列。 《白色相簿：编缀的冬日回忆》是一个描绘了各种形式的恋爱的爱情故事。以其独特的剧情和迷人的角色而获得人气，并于2009年改编成动漫作品。编缀而成的冬日相簿，如此雪白而凄美—— \",\n" +
            "    \"date\": \"2023 年 8 月 4 日\",\n" +
            "    \"developer\": \"AQUAPLUS\",\n" +
            "    \"publisher\": \"DMM GAMES\",\n" +
            "    \"tags\": [\n" +
            "      \"视觉小说\",\n" +
            "      \"90年代\",\n" +
            "      \"爱情\",\n" +
            "      \"恋爱模拟\",\n" +
            "      \"剧情丰富\"\n" +
            "    ],\n" +
            "    \"image\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/2432110/header.jpg\",\n" +
            "    \"images\": [\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/2432110/ss_1902e6447d55746b5831eb4c92e4161af4385b6d.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/2432110/ss_476466ae083afe8167ee6ae3c6da8102008a3fb0.600x338.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/2432110/ss_7499f463d4b993edb34ad5cc6523955a92792b4f.600x338.jpg\"\n" +
            "      }\n" +
            "    ]\n" +
            "  },\n" +
            "  {\n" +
            "    \"id\": 100,\n" +
            "    \"categoryId\": 2,\n" +
            "    \"name\": \"极限竞速：地平线 4\",\n" +
            "    \"price\": 188,\n" +
            "    \"description\": \"在世界上最盛大的汽车嘉年华上，不断变化的赛季改变着一切。单枪匹马或者与其他人组队，在一个共享开放世界中探索美丽而富有历史气息的英国。收集、改装和驾驶超过 450 辆车辆。尽情竞速、表演特技、创造和探索：选择您专属的方式来成为地平线中的超级巨星。 \",\n" +
            "    \"developer\": \"Playground Games\",\n" +
            "    \"publisher\": \"Xbox Game Studios\",\n" +
            "    \"tags\": [\n" +
            "      \"竞速\",\n" +
            "      \"开放世界\",\n" +
            "      \"驾驶\",\n" +
            "      \"多人汽车\",\n" +
            "      \"模拟\",\n" +
            "      \"拟真\"\n" +
            "    ],\n" +
            "    \"image\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1293830/header.jpg\",\n" +
            "    \"images\": [\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1293830/ss_e872c3153b246b4f595d7106976c6e63d4185c45.600x338.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1293830/ss_6aff9bfcaeb460988148efe3c83448fd93e6641a.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1293830/ss_c0271116cbfb7be15679861e4b5d0549826dbb04.1920x1080.jpg\"\n" +
            "      }\n" +
            "    ]\n" +
            "  },\n" +
            "  {\n" +
            "    \"id\": 101,\n" +
            "    \"categoryId\": 2,\n" +
            "    \"name\": \"极限竞速：地平线 5\",\n" +
            "    \"price\": 248,\n" +
            "    \"description\": \"您的“终极地平线冒险”即将开启！驾驶世界名车，探索墨西哥充满活力的户外景色，享受无拘无束又充满乐趣的驾驶体验。在终极地平线拉力赛中征服富有挑战的塞拉努埃瓦。需拥有《极限竞速：地平线 5》才能体验，扩充内容需另购。\",\n" +
            "    \"developer\": \"Playground Games\",\n" +
            "    \"publisher\": \"Xbox Game Studios\",\n" +
            "    \"image\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1551360/header.jpg\",\n" +
            "    \"tags\": [\n" +
            "      \"竞速\",\n" +
            "      \"开放世界\",\n" +
            "      \"驾驶\",\n" +
            "      \"多人汽车\",\n" +
            "      \"模拟\",\n" +
            "      \"拟真\"\n" +
            "    ],\n" +
            "    \"images\": [\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1551360/ss_cf56e25a0290556ba83229eb0ab370d10be0407c.600x338.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1551360/ss_00f0090174380eeaf8753bd3d1028b6772c3aebf.600x338.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1551360/ss_b65236b365315ebb6da6114ce42cd74b59cab3c8.600x338.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1551360/ss_733100a0e305025cfea4797c14cb55a9e2673521.600x338.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1551360/ss_4f2da231c28c5cb6a1ed4f62aaad6f51ca4a5c05.600x338.jpg\"\n" +
            "      }\n" +
            "    ]\n" +
            "  },\n" +
            "  {\n" +
            "    \"id\": 1000,\n" +
            "    \"categoryId\": 3,\n" +
            "    \"name\": \"魔女的夜宴\",\n" +
            "    \"price\": 88,\n" +
            "    \"description\": \"《魔女的夜宴》是日本超人气美少女游戏品牌YUZUSOFT（柚子社）的经典名作。女主角绫地宁宁由当红声优桐谷华配音，是该社历代作品中最具代表性的女主角之一。国际中文版拥有超越原版的1920X1080的高清画质。本作也曾在美少女游戏大赏和萌系游戏大赏中斩获众多奖项。 \",\n" +
            "    \"date\": \"2022 年 3 月 25 日\",\n" +
            "    \"developer\": \"Yuzusoft\",\n" +
            "    \"publisher\": \"HIKARI FIELD\",\n" +
            "    \"image\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/2458530/header.jpg\",\n" +
            "    \"tags\": [\n" +
            "      \"视觉小说\",\n" +
            "      \"第一人称射击\",\n" +
            "      \"恋爱模拟\",\n" +
            "      \"休闲冒险+\"\n" +
            "    ],\n" +
            "    \"images\": [\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/2458530/ss_4367b4f226e17f18b5b9f71a7af227b561806690.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/2458530/ss_d7a01499c1ba980d356758c3e172a7da4e256506.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/2458530/ss_bcdb988c90a0aa81fc1150eaf7fa1c0ca01618bc.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/2458530/ss_ca3353ca61039c0e9d1647f41e066a38c217f353.1920x1080.jpg\"\n" +
            "      }\n" +
            "    ]\n" +
            "  },\n" +
            "  {\n" +
            "    \"id\": 1001,\n" +
            "    \"categoryId\": 3,\n" +
            "    \"name\": \"星光咖啡馆与死神之蝶\",\n" +
            "    \"price\": 88,\n" +
            "    \"description\": \"《星光咖啡馆与死神之蝶》是日本美少女游戏品牌Yuzusoft（柚子社）制作的恋爱题材作品。本作仍由创作多款人气作品的柚子社主创团队担当制作，发售后在美少女游戏大赏中囊括了囊括了综合、图像、音乐、剧本、影片、角色等诸多奖项。游戏主题曲《Smiling-Swinging!!》由人气歌姬米仓千寻献唱。 \",\n" +
            "    \"date\": \"2022 年 3 月 25 日\",\n" +
            "    \"developer\": \"Yuzusoft\",\n" +
            "    \"publisher\": \"NekoNyan Ltd., HIKARI FIELD\",\n" +
            "    \"image\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1829980/header_schinese.jpg\",\n" +
            "    \"tags\": [\n" +
            "      \"视觉小说\",\n" +
            "      \"第一人称射击\",\n" +
            "      \"恋爱模拟\",\n" +
            "      \"休闲冒险+\"\n" +
            "    ],\n" +
            "    \"images\": [\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1829980/ss_fd1b52cb5cb11da9e2d3be55727c1b426ff0c8ea.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1829980/ss_68fff9c89b141a5d2267c24b5cfd66a8e1f2a2df.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1829980/ss_d7d6cb731910936fb1d479d43675f90d18cacc40.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1829980/ss_e4e5e72b13a684850a14645e9df6e7d97e3472ff.1920x1080.jpg\"\n" +
            "      }\n" +
            "    ]\n" +
            "  },\n" +
            "  {\n" +
            "    \"id\": 1002,\n" +
            "    \"categoryId\": 3,\n" +
            "    \"name\": \"千恋 * 万花\",\n" +
            "    \"price\": 88,\n" +
            "    \"description\": \"gal界原神，启动！\",\n" +
            "    \"date\": \"2022 年 3 月 25 日\",\n" +
            "    \"developer\": \"Yuzusoft\",\n" +
            "    \"publisher\": \"NekoNyan Ltd., HIKARI FIELD\",\n" +
            "    \"image\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1144400/header_schinese.jpg\",\n" +
            "    \"tags\": [\n" +
            "      \"视觉小说\",\n" +
            "      \"第一人称射击\",\n" +
            "      \"恋爱模拟\",\n" +
            "      \"休闲冒险+\"\n" +
            "    ],\n" +
            "    \"images\": [\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1144400/ss_4a46863d9f7bdb58dfa22b15b25845b2b02d5707.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1144400/ss_47f41329f47bf3ba7a23a4efd26e90033b153963.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1144400/ss_6910d415d71b11829fb7af79c505b390346de9d6.1920x1080.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1144400/ss_ee496a558fd3bb7967414927b4a87e6a06441095.1920x1080.jpg\"\n" +
            "      }\n" +
            "    ]\n" +
            "  },\n" +
            "  {\n" +
            "    \"id\": 114514,\n" +
            "    \"categoryId\": 1919810,\n" +
            "    \"name\": \"命运2：光陨之秋(DLC)\",\n" +
            "    \"price\": 198,\n" +
            "    \"description\": \"上线一个月就达到了20%的好评率，我们真是太厉害辣。\",\n" +
            "    \"date\": \"2023 年 8 月 4 日\",\n" +
            "    \"developer\": \"Bungie\",\n" +
            "    \"publisher\": \"Bungie\",\n" +
            "    \"tags\": [\n" +
            "      \"开放世界\",\n" +
            "      \"第一人称射击\",\n" +
            "      \"刷宝射击游戏\"\n" +
            "    ],\n" +
            "    \"image\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1945340/header_schinese.jpg\",\n" +
            "    \"images\": [\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1945340/ss_abaef766fe06870ea9bb5b12fa47b6e09906a839.600x338.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1945340/ss_1a7b691560cc2b1026750fb89ba1b15d306ae252.600x338.jpg\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"url\": \"https://cdn.cloudflare.steamstatic.com/steam/apps/1945340/ss_1a7b691560cc2b1026750fb89ba1b15d306ae252.600x338.jpg\"\n" +
            "      }\n" +
            "    ]\n" +
            "  }\n" +
            "]";
    private static Category[] categories = null;

    private static Item[] items = null;

    /**
     * Returns all categories in the database
     * @return Category[], the reference of all categories
     */
    public static Category[] getCategories() {
        if (categories == null) {
            try {
//                actually it will not throw error until json was modified
            categories = Utils.JsonConverter.fromJsonString(categoryJsonStr, Category[].class);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return categories;
    }

    /**
     * Returns all items in the database
     * @return Item[], the reference of all items
     */
    public static Item[] getItems() {
        if (items == null) {
            try {
//                actually it will not throw error until json was modified
                items = Utils.JsonConverter.fromJsonString(ItemsJsonStr, Item[].class);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return items;
    }

    public static Item getItemById(int id) {
        Item[] items = getItems();
        for (Item item : items) {
            if (item.id == id) {
                return item;
            }
        }
        return null;
    }
}