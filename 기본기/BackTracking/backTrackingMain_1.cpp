#include <iostream>

using namespace std;

int cnt;
void run(int level, int sum) {
    // 가지치기 1.
    if (sum > 10) return;

    if (level == 5) {
        if (sum == 10) cnt++;
        return;
    }
    for (int i = 1; i <= 4; i++) {  // 브랜치가 네 개
        // if (sum + i > 10) continue; // 가지치기 2.
        run(level + 1, sum + i);
        /* 
          sum += i라고 하면 중간 단계에서 sum 값들이 다른 값으로 아예
          저장되므로 backtracking하기 힘들다. 중간 중간 임시저장한다고 생각할 것
        */
    }
}
/*
 가지치기 방법은 두 가지이다.
 1. 맨 위에 적는 방법. = 다음 재귀로 들어간 후에 원하는 값이 아닐 때 리턴하는 것.
 2. 재귀의 내용에 적는 방법. = 원하는 값이 아니라면 다음 재귀로 아예 안 들어가는 것.


*/

int main() {

    run(0, 0);

    cout << cnt;

    return 0;
}