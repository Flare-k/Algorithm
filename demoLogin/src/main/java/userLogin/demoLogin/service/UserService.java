package userLogin.demoLogin.service;

import lombok.RequiredArgsConstructor;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;
import userLogin.demoLogin.domain.UserInfo;
import userLogin.demoLogin.dto.UserInfoDto;
import userLogin.demoLogin.repository.UserRepository;

@RequiredArgsConstructor    // 초기화 되지 않은 final 필드나, @NonNull 이 붙은 필드에 대해 생성자를 생성해준다.
@Service
public class UserService implements UserDetailsService {

    private final UserRepository userRepository;

    /**
     * 회원가입 -> 회원정보 저장
     * @param infoDto 회원정보가 들어있는 DTO
     * @return 저장되는 회원의 PK
     */
    public Long save(UserInfoDto infoDto) {
        BCryptPasswordEncoder encoder = new BCryptPasswordEncoder();
        infoDto.setPassword(encoder.encode(infoDto.getPassword()));

        return userRepository.save(UserInfo.builder()
        .email(infoDto.getEmail())
        .auth(infoDto.getAuth())
        .password(infoDto.getPassword()).build()).getCode();
    }


    /**
     *  로그인을 위한 Spring Security 메소드 구현
     * @params email
     * @return UserDetails
     * @throws UsernameNotFoundException 유저가 없을 때 예외 발생
     */
    // 기본적인 반환 타입은 UserDetails, UserDetails를 상속받은 UserInfo로 반환 타입 지정 (자동으로 다운 캐스팅됨)
    @Override
    public UserInfo loadUserByUsername(String email) throws UsernameNotFoundException {
        return userRepository.findByEmail(email)
                .orElseThrow(() -> new UsernameNotFoundException((email)));
    }

}
