package com.lab4.restservice.api.banner;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class BannerController {
    @GetMapping("/banner")
    @Deprecated
    public String getBanner() {
        return "Banner";
    }
}
