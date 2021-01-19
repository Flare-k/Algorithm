package userLogin.demoLogin.controller;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import userLogin.demoLogin.dto.UserInfoDto;
import userLogin.demoLogin.service.UserService;

@RequiredArgsConstructor
@Controller
public class UserController {

    private final UserService userService;

    @PostMapping("/user")
    public String signup(UserInfoDto infoDto) {
        userService.save(infoDto);
        return "redirect:/login";
    }
}
