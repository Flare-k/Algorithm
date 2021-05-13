#include <iostream>
#include <algorithm>
using namespace std;

// 부루마블
// 말은 +1, +2, *2 의 세 가지 방법으로 이동가능하다고 가정

int marble[15] = {0, 3, 4, 1, 2, 5, 3, -1, -3, -5, -2, 4, 1, 9, 0}; // 28
// int marble[11] = {0, 7, -3, -5, 4, -2, 6, 5, -9, -1, 0}; // 18
int acc[11];
int maxS = -21e8;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;

    for (int i = 0; i < 15; i++) {
        if (i % 2 == 1) {
            marble[i] = max(marble[i] + marble[i - 1], marble[i] + marble[i - 2]);
        }
        else {
            int a = max(marble[i] + marble[i - 1], marble[i] + marble[i - 2]);
            marble[i] = max(a, marble[i] + marble[i / 2]);
        }
    }

    cout << marble[14];

    return 0;
}
// sol) 각 위치에서 -1, -2의 위치에서의 결과와 합산한다. 단, 짝수번째의 경우 /2도 확인한다.