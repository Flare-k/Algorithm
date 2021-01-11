#include <iostream>
#include <vector>
using namespace std;

int N;
int col[15];
int result = 0;

bool promising(int i) {
    for (int j = 0; j < i; j++) {
        // 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
        if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j)) return false;
        // col[j]가 의미하는 것이 X좌표, j가 의미하는것이 Y좌표이므로 차이가
        // 일정하다면 대각선에 있다고 볼 수 있다.
    }
    return true;
}
void N_Queen(int i) {
    if (i == N)
        result += 1;
    else {
        for (int j = 0; j < N; j++) {
            col[i] = j;
            if (promising(i))  // 유효하면 다음행에 퀸 배치, 그렇지 않다면
                                // 다른위치로 퀸배치 변경
                N_Queen(i + 1);
        }
    }
}

int main() {
   cin >> N;

   N_Queen(0);

   cout << result << endl;

   return 0;
}