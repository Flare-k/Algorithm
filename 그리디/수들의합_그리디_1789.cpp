#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll sum = 0;
    int cnt = 0;
    
    for (int i = 1; sum <= n; i++) {
        sum += i;
        cnt++;
    }

    cout << cnt - 1;    // 맨 마지막 종료조건을 통과하며 한번더 카운팅되므로 하나 빼준다.
    
    return 0;
}