#include <iostream>
using namespace std;

// 분할정복
long long run(int A, int B, int C) {
    if (B == 0) return 1;

    long long N = run(A, B / 2, C);
    long long tmp = N * N % C;

    if (B % 2 == 0) return tmp;
    else return A * tmp % C;
}

// A를 B번 곱한 수를 C로 나눈 나머지 출력하기
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long A, B, C;
    cin >> A >> B >> C;
    cout << run(A, B, C) << '\n';
    
    return 0;
}