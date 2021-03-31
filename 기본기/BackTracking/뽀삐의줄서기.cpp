#include <iostream>
using namespace std;

// 중복 제거, 특정 값 used에 미리 할당

int used[7];
char path[7];
int cnt;

void peed(int level, int a, int b) {
    if (level == 6) {
        cnt++;
        return;
    }

    for (int i = 1; i <= 6; i++) {
        // 뽀삐를 1이라 가정
        if (i == 1 && (level == a - 1 || level == b - 1)) continue;
        if (used[i] == 1) continue;
        
        used[i] = 1;
        peed(level + 1, a, b);
        used[i] = 0;
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    peed(0, a, b);

    cout << cnt;

    return 0;
}