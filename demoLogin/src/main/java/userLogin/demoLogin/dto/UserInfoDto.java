package userLogin.demoLogin.dto;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class UserInfoDto {
    // 회원가입을 위해
    // Form으로 받을 회원정보를 매핑 시켜줄 객체를 만든다.
    private String email;
    private String password;
    private String auth;
}
