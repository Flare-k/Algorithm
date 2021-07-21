#include <iostream>
#include <algorithm>
using namespace std;

int cost[3];
int truck[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++){
        cin >> cost[i];
    }

    int ts = 21e8;
    int te = -21e8;

    for (int i = 0; i < 3; i++) {
        int s, e;
        cin >> s >> e;

        ts = min(ts, s);
        te = max(te, e);

        for (int j = s; j < e; j++) {
            truck[j]++;
        }
    }

    int timeTerm = 1;    // 시간 간격
    int price = 0;
    for (int i = ts; i <= te; i++) {
        if (truck[i] != truck[i + 1]) {
            price += timeTerm * cost[truck[i] - 1] * truck[i];
            timeTerm = 1;
        }
        else {
            timeTerm++;
        }
    }

    cout << price;

    return 0;
}