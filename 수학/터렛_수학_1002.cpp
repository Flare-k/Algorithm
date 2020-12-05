#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int repeat;
    cin >> repeat;

    while (repeat--) {
        int x1, y1, r1, x2, y2, r2;
        int a = 1, b = 1;
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        int minus = abs(r1 - r2);
        int plus = r1 + r2;

        int ans = 0;

        if (dist == 0) {  // 같은 좌표 내에서..
            if (r1 == r2)
                ans = -1; 
            else 
                ans = 0;
        } 
        else {
            if (minus < dist && dist < plus)
                ans = 2;
            else if (plus == dist || minus == dist)
                ans = 1;
            else
                ans = 0;
        }

        cout << ans << '\n';
    }

    return 0;
    
}
