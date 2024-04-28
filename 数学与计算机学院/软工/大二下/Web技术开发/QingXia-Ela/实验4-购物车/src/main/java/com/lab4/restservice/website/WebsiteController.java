package com.lab4.restservice.website;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/")
public class WebsiteController {
    @RequestMapping("/")
    public String index() {
        return "index.html";
    }
}
