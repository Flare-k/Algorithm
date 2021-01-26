package com.teamApple.apple.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * Thymeleaf 예
 */
@Controller
public class GreetingController {

    @GetMapping("/greeting") // 1. /greeting URL을 GET 메소드로 요청하면..
    public String greeting(@RequestParam(name="name", required=false, defaultValue="World") String name, Model model) {
        // 2. /greeting?name이라는 URL을 준다. 파라미터에 있는 name이 값이 있으면 셋팅이 된다.값이 없으면 defaultValue로 셋팅된다.
        model.addAttribute("name", name);
        return "greeting";
    }

}