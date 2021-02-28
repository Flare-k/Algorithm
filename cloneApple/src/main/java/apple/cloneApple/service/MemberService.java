package apple.cloneApple.service;

import apple.cloneApple.model.Member;
import apple.cloneApple.model.Role;
import apple.cloneApple.repository.MemberRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

@Service
public class MemberService {

    @Autowired
    private MemberRepository memberRepository;

    @Autowired
    private PasswordEncoder passwordEncoder;    //비밀번호 암호화

    public Member save(Member member) {

        String encodedPassword = passwordEncoder.encode(member.getPassword());
        member.setPassword(encodedPassword);

        Role role = new Role();
        role.setMember_id(1l);
        member.getRoles().add(role);  // role을 어떤 권한을 줄 것인지 저장한다. user_role 테이블에 role_id가 저장된다.

        return memberRepository.save(member);
    }
}
