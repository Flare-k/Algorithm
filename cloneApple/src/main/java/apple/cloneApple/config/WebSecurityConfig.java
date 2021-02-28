package apple.cloneApple.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

import javax.sql.DataSource;


@Configuration
@EnableWebSecurity
public class WebSecurityConfig extends WebSecurityConfigurerAdapter {

    @Autowired
    private DataSource dataSource;  // application.properties에 있는 datasource를 사용할 수 있게 하는 인스턴스

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
                .authorizeRequests()
                .antMatchers("/", "/member/register", "/css/**", "/api/**").permitAll()
                .anyRequest().authenticated()
                .and()
                .formLogin()
                .loginPage("/member/login")
                .permitAll()
                .and()
                .logout()
                .permitAll();
    }

    @Autowired
    public void configureGlobal(AuthenticationManagerBuilder auth)
            throws Exception {
        auth.jdbcAuthentication()
                .dataSource(dataSource) //jdbcAuthentication에 dataSource를 넘겨주면 스프링에서 인증처리를 한다.
                .passwordEncoder(passwordEncoder())
                .usersByUsernameQuery("select email, password "
                        + "from member "
                        + "where email = ?")    // Authentication
                .authoritiesByUsernameQuery("select u.member_name, r.member_name "
                        + "from user_role ur inner join member u on ur.member_id = u.member_id "
                        + "inner join role r on ur.role_id = r.member_id "
                        + "where u.member_name = ?");   // Authority
        // USER 뿐만 아니라 권한처리에 대한 테이블도 생성..
        // USER와 ROLE을 연결시켜주는 Mapping Table도 필요하다.
    }

    //Configuration을 했기때문에 Bean을 생성할 수 있다.
    @Bean
    public PasswordEncoder passwordEncoder() {
        return new BCryptPasswordEncoder();
    }
}