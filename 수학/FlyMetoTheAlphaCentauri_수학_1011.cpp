#include <iostream>
#define ll long long
using namespace std;

int t, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> x >> y;

        ll z = y - x;
        ll k = 0;
        ll cnt = 0;

        // 가운데에서 길이가 큰 것을 착안
        // 예) 1-2-3-2-1 .. 그럼 좌우 끝에서부터 수를 키워가며 더해주면될것
        for (ll i = 1 ; i <= 21e8; i++) {
            cnt++;
            k += i;
            if (z <= k) break;
            
            cnt++;
            k += i;
            if (z <= k) break;
        }

        cout << cnt << '\n';
    }


    return 0;
}