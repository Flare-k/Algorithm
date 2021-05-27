#include <iostream>
using namespace std;

// k만큼가면 k만큼 건전지 소모 , 온거리x2 순간이동은 건건지 소모 ㄴㄴ
// 건전지 사용량의 최솟값 리턴

int solution(int n) {
    int ans = 0;

    while (n != 0) {
        if (n % 2 == 0) n/= 2;
        else {
            n--;
            ans++;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << solution(n);

    return 0;
}