package com.lab4.restservice.api.items;

import com.lab4.db.Database;
import com.lab4.db.Item;
import org.springframework.web.bind.annotation.*;

@RestController
public class ItemsController {
    @GetMapping("/viewall")
    public Item[] getItems() {
        return Database.getItems();
    }

    @GetMapping("/shopitem/{id}")
    public Item getItem(@PathVariable("id") String id) {
        Item[] items = Database.getItems();

        for (Item item : items) {
            if (String.valueOf(item.id).equals(id)) {
                return item;
            }
        }

        throw new RuntimeException("Item not found");
    }
}
