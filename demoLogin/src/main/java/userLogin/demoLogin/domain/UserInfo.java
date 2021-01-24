package userLogin.demoLogin.domain;

import lombok.AccessLevel;
import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;

import javax.persistence.*;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;

/**
 * User 엔티티는 UserDetails를 상속받아서 구현한다. UserDetails에서 필수로 구현해야 하는 메소드는 다음과 같다.
 * getAuthorities() - 사용자의 권한을 Collection으로 리턴
 * getUsername() - 사용자의 ID 리턴
 * getPassword() - 사용자의 Password 리턴
 * isAccountNonExpired() - 계정 만료 여부 반환 (true=만료되지 않음을 의미)
 * isAccountNonLocked() - 계정 잠 여부 반환 (true=잠금되지 않음을 의미)
 * isCredentialsNonExpired() - 패스워드 만료여부 반환 (true=만료되지 않음을 의미)
 * isEnabled() - 계정 사용 가능 여부 반환 (true=사용 가능을 의미)
 */

@NoArgsConstructor(access = AccessLevel.PROTECTED)
@Entity // Entity 어노테이션을 클래스에 선언하면 이 클래스는 JPA가 관리한다. DB의 테이블과 Class(VO, DTO)와 맵핑한다면 반드시 @엔티티를 붙여야 한다.
@Getter
public class UserInfo implements UserDetails {

    @Id
    @Column(name = "code")  // Column 어노테이션은 객체 필드와 DB 테이블 Column을 맵핑한다.
                            // name: 맵핑할 테이블의 컬럼 이름을 지정한다.
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long code;

    @Column(name = "email", unique = true)
    private String email;

    @Column(name = "password")
    private String password;

    @Column(name = "auth")
    private String auth;

    @Builder
    public UserInfo(String email, String password, String auth) {
        this.email = email;
        this.password = password;
        this.auth = auth;
    }


    /**
     * 사용자의 권한을 Collection 형태로 리턴
     * 단, 클래스 자료형은 GrantedAuthority를 구현해야 한다.
     */
    @Override
    public Collection<? extends GrantedAuthority> getAuthorities() {
        // 콜렉션의 자료형은 무조건적으로 GrantedAuthority를 구현해야 한다.
        // ADMIN의 auth는 "ROLE_ADMIN,ROLE_USER"와 같은 형태로 전달이 될 것이고,
        // 쉼표(,) 기준으로 잘라서 ROLE_ADMIN과 ROLE_USER를 roles에 추가해준다.
        Set<GrantedAuthority> roles = new HashSet<>();

        for (String role : auth.split(",")) {
            roles.add(new SimpleGrantedAuthority(role));
        }

        return roles;
    }

    @Override
    public String getUsername() {
        return email;
    }

    @Override
    public String getPassword() {
        return password;
    }

    @Override
    public boolean isAccountNonExpired() {
        return true;
    }

    @Override
    public boolean isAccountNonLocked() {
        return true;
    }

    @Override
    public boolean isCredentialsNonExpired() {
        return true;
    }

    @Override
    public boolean isEnabled() {
        return true;
    }

}
