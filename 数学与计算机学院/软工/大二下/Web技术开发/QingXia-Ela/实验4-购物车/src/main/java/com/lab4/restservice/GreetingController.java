package com.lab4.restservice;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.concurrent.atomic.AtomicLong;

@RestController
public class GreetingController {
    public static final String template = "Hello, %s!";
    private final AtomicLong counter = new AtomicLong();

    @GetMapping("/greeting")
    public com.lab4.restservice.Greeting greeting(@RequestParam(value = "name", defaultValue = "World") String name) {
        return new com.lab4.restservice.Greeting(counter.incrementAndGet(), String.format(template, name));
    }
}
