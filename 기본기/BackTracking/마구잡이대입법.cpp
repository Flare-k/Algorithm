#include <iostream>
using namespace std;

/*
  - 숫자 n을 입력
  - 0~9 사이의 숫자 n개를 사용해서 모두 더했을 때
  - 7이 나오는 경우가 총 몇 가지인지 출력
    *조건 
    // 2 <= n <= 6
    // Brute-force로 풀이
    )
  
  내가 생각하는 branch와 level
  branch : n, level : 합이 7인 경우
*/

int ans = 0;

void run(int level, int sum, int n) {
    if (n < 0) return;

    if (sum == 7 && n == 0) {
        ans++;
        return;
    }

    for (int i = 0; i < 10; i++) {
        run(level + 1, sum + i, n - 1);
    }
}

int main() {
    int n;
    cin >> n;

    run(0, 0, n);

    cout << ans;

    return 0;
}