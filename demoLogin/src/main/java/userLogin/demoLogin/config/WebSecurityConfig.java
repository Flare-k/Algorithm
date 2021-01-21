package userLogin.demoLogin.config;


import lombok.Builder;
import lombok.RequiredArgsConstructor;
import org.springframework.boot.autoconfigure.condition.ConditionalOnBean;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.builders.WebSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import userLogin.demoLogin.service.UserService;

@RequiredArgsConstructor
@EnableWebSecurity // 1. Spring Security 활성화
@Configuration

public class WebSecurityConfig extends WebSecurityConfigurerAdapter { // 2
    //WebSecurityConfigurerAdapter는 Spring Security의 설정파일
    private final UserService userService; // 3

    @Bean
    public PasswordEncoder passwordEncoder() {
        // 4. 비밀번호를 암호화할 때 사용할 인코더를 미리 빈으로 등록
        return new BCryptPasswordEncoder();
    }

    @Override
    public void configure(WebSecurity web) {
        // 5. WebSecurityConfigurerAdapter를 상속받으면 오버라이드할 수 있다.
        // 인증을 무시할 경로들을 설정해놓을 수 있다.
        web.ignoring().antMatchers("/css/**", "/js/**", "/img/**", "/h2-console/**");
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        // 6. Http 관련 인증 설정이 가능하다.
        http
                .authorizeRequests() // 7
                .antMatchers("/login", "/signup", "/user").permitAll() // 누구나 접근 허용
                .antMatchers("/").hasRole("USER") // USER, ADMIN만 접근 가능
                .antMatchers("/admin").hasRole("ADMIN") // ADMIN만 접근 가능
                .anyRequest().authenticated() // 나머지 요청들은 권한의 종류에 상관 없이 권한이 있어야 접근 가능
                .and()
                .formLogin() // 8
                .loginPage("/login") // 로그인 페이지 링크
                .defaultSuccessUrl("/") // 로그인 성공 후 리다이렉트 주소
                .and()
                .logout() // 9
                .logoutSuccessUrl("/login") // 로그아웃 성공시 리다이렉트 주소
                .invalidateHttpSession(true) // 세션 날리기
        ;
    }

    @Override
    public void configure(AuthenticationManagerBuilder auth) throws Exception {
        // 10. 로그인할 때 필요한 정보를 가져오는 곳
        // passwordEncoder는 아까 등록해놓은 passwordEncoder를 사용한다. (BCrypt)
        auth.userDetailsService(userService).passwordEncoder(passwordEncoder());
        // 해당 서비스(userService)에서는 UserDetailsService를 implements해서 loadUserByUsername() 구현해야함 (서비스 참고)
    }
}
