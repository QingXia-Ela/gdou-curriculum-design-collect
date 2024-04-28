package com.lab4.restservice.api.recommand;

import com.lab4.Utils;
import com.lab4.db.Category;
import com.lab4.db.Database;
import com.lab4.db.Item;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

class ResponseItem {
    public Item item;
    public Item want;
    public String desc;

    public ResponseItem(Item item, Item want, String desc) {
        this.item = item;
        this.want = want;
        this.desc = desc;
    }
}

@RestController
public class RecommendController {
    @GetMapping("/recommend")
    public ResponseItem[] recommend() {
        Category[] categories = Database.getCategories();

        ResponseItem[] responseItems = new ResponseItem[2];

//        pick horizon
        Category horizon = categories[1];
//        horizon only has 2 items
        ResponseItem i1 = new ResponseItem(Database.getItemById(horizon.items[0]), Database.getItemById(horizon.items[1]), "因为您想要");

//        pick yuzusoft
        Category yuzusoft = categories[2];
        ResponseItem i2 = new ResponseItem(Database.getItemById(yuzusoft.items[0]), Database.getItemById(yuzusoft.items[Utils.random(1, yuzusoft.items.length - 1)]), "因为您最近浏览了");

        responseItems[0] = i1;
        responseItems[1] = i2;

        return responseItems;
    }
}
