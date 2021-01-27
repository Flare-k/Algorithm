#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /**
     * 1. 거스름돈을 못주는 경우는 5원보다 적고 2의 배수가 아닌 1원과 3원일 때이다.
     * 2. 가장 최소의 갯수로 거슬러 주어야 하므로 큰 수인 5부터 나눈다.
     * 3. 5로 나눈 나머지가 홀수인 경우, 나머지에서 5원을 더해 5원 대신 나머지 + 5원을 2원으로 거슬러 주면 된다.
     */
    int n;
    cin >> n;

    int r = n % 5;  // 5로 나눈 나머지

    if (n == 1 || n == 3) {
        cout << -1;
    }
    else if (r % 2 == 0) {
        cout << (n / 5) + (r / 2);
    }
    else {      // 3.
        cout << ((n / 5) - 1) + ((r + 5) / 2);
    }

   return 0;
}