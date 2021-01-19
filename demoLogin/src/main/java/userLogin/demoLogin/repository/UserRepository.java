package userLogin.demoLogin.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import userLogin.demoLogin.domain.UserInfo;

import java.util.Optional;

public interface UserRepository extends JpaRepository<UserInfo, Long> {
    Optional<UserInfo> findByEmail(String email);
}
