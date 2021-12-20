#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

/*
모듈러는 곱셈이나 덧셈에서 사용 가능하지만 분수에선 적용하기 어려우므로 페르마의 소정리를 이용한다.
= p가 소수이고 a가 p의 배수가 아니면, a^(p-1) = 1(mod p) 이다.
즉, a^(p-1)을 p로 나눈 나머지는 1이다.
*/

const ll MAX = 1000000007;
ll A, B, half;

ll run(int x) {
    if (x == 0) return 1;

    if (x % 2 == 1) return B * run(x - 1) % MAX;
    else {
        half = run(x / 2);
        return half * half % MAX;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    A = 1, B = 1;

    for (int num = N; num >= N - K + 1; num--) {
        A = (A * num) % MAX;
    }

    for (int num = 1; num <= K; num++) {
        B = (B * num) % MAX;
    }

    B = run(MAX - 2);

    cout << (A * B) % MAX;

    return 0;
}