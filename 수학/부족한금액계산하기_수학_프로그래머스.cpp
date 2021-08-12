#include <iostream>
using namespace std;

long long solution(int price, int money, int count) {
    long long sum = 1LL * price * count * (count + 1) / 2;
    return sum <= money ? 0 : sum - money;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << solution(3, 20, 4) << '\n';

    return 0;
}