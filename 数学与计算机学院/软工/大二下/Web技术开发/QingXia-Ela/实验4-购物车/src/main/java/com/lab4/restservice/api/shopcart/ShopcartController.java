package com.lab4.restservice.api.shopcart;

import com.lab4.db.Database;
import com.lab4.db.Item;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;

class BuyItem {
    public int id;
    public int count;
    public boolean selected;

    public BuyItem(int id, int count, boolean selected) {
        this.id = id;
        this.count = count;
        this.selected = selected;
    }
}

class ResponseBuyItem {
    public Item item;
    public int count;
    public boolean selected;

    public ResponseBuyItem(Item item, int count, boolean selected) {
        this.item = item;
        this.count = count;
        this.selected = selected;
    }
}

class OperateResult {
    public int code;
    public String msg;

    public OperateResult(int code, String msg) {
        this.code = code;
        this.msg = msg;
    }

    public OperateResult() {
        this.code = 0;
        this.msg = "success";
    }
}

@RestController
public class ShopcartController {
    private final ArrayList<BuyItem> items = new ArrayList<>();

    BuyItem[] parseResponseItems2Items(ArrayList<ResponseBuyItem> items) {
        ArrayList<BuyItem> list = new ArrayList<>();

        for (ResponseBuyItem item : items) {
            list.add(new BuyItem(item.item.id, item.count, item.selected));
        }

        BuyItem[] result = new BuyItem[list.size()];
        list.toArray(result);

        return result;
    }

    ResponseBuyItem[] parseItems2ResponseItems(ArrayList<BuyItem> items) {
        ArrayList<ResponseBuyItem> list = new ArrayList<>();

        for (BuyItem item : items) {
            list.add(new ResponseBuyItem(Database.getItemById(item.id), item.count, item.selected));
        }

        ResponseBuyItem[] result = new ResponseBuyItem[list.size()];
        list.toArray(result);

        return result;
    }

    @PostMapping("/shopcart/add")
    public OperateResult add(@RequestBody String id) {
        Item i = Database.getItemById(Integer.parseInt(id));
        if (i == null) {
            return new OperateResult(-1, "item not found");
        } else {
            synchronized (items) {
                for (BuyItem item : items) {
                    if (item.id == i.id) {
                        item.count++;
                        return new OperateResult();
                    }
                }
                items.add(new BuyItem(i.id, 1, true));
                return new OperateResult();
            }
        }
    }

    @GetMapping("/shopcart/include/{id}")
    public boolean include(@PathVariable("id") int id) {
        boolean include = false;
        synchronized (items) {
            for (BuyItem item : items) {
                if (item.id == id) {
                    include = true;
                    break;
                }
            }
        }
        return include;
    }
    /**
     * Replace old items with new items
     */
    @PostMapping("shopcart/modify")
    public OperateResult modify(@RequestBody BuyItem[] items) {
        synchronized (this.items) {
            this.items.clear();
            this.items.addAll(Arrays.asList(items));
        }

        return new OperateResult();
    }

    @GetMapping("/shopcart/checkout")
    public String checkout() {
        int moneySum = 0;

        synchronized (items) {
            for (BuyItem item : items) {
                if (item.selected) {
                    moneySum += Objects.requireNonNull(Database.getItemById(item.id)).price * item.count;
                }
            }
        }

        return String.valueOf(moneySum);
    }

    @GetMapping("/shopcart/remove/{id}")
    public OperateResult remove(@PathVariable("id") int id) {
        if (!items.removeIf((i) -> i.id == id)) {
            return new OperateResult(-1, "item not found");
        };
        return new OperateResult();
    }

    @GetMapping("/shopcart/status")
    public ResponseBuyItem[] status() {
        return parseItems2ResponseItems(items);
    }
}
