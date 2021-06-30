#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

int dice[7];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int s, m, e;
    set<int> caseOfThrow;
    int maxx = -1;

    for (int i = 0; i < n; i++) {
        memset(dice, 0, sizeof(dice));
        caseOfThrow.clear();

        cin >> s >> m >> e;

        caseOfThrow.insert(s);
        caseOfThrow.insert(m);
        caseOfThrow.insert(e);

        dice[s]++;
        dice[m]++;
        dice[e]++;

        int price = 0;

        if (caseOfThrow.size() == 1) {
            price = 10000 + (s)*1000;
        }
        else if (caseOfThrow.size() == 2) {
            for (int num : caseOfThrow) {
                if (dice[num] == 2) {
                    price = 1000 + num * 100;
                    break;
                }
            }
        }
        else {
            for (int i = 6; i > 0; i--) {
                if (dice[i] == 1) {
                    price = 100 * i;
                    break;
                }
            }
        }

        maxx = max(maxx, price);

    }

    cout << maxx;

    return 0;
}