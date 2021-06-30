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

    int first, second, third, fourth;
    set<int> caseOfThrow;
    int maxx = -1;

    for (int i = 0; i < n; i++) {
        memset(dice, 0, sizeof(dice));
        caseOfThrow.clear();

        cin >> first >> second >> third >> fourth;

        caseOfThrow.insert(first);
        caseOfThrow.insert(second);
        caseOfThrow.insert(third);
        caseOfThrow.insert(fourth);

        dice[first]++;
        dice[second]++;
        dice[third]++;
        dice[fourth]++;

        int price = 0;

        if (caseOfThrow.size() == 1) {
            price = 50000 + (first)*5000;
        }
        else if (caseOfThrow.size() == 2) {
            bool flag = false;
            for (int num : caseOfThrow) {
                if (dice[num] == 3) {
                    price = 10000 + num*1000;
                    break;
                }
                else if (dice[num] == 2) {
                    price += num * 500;
                    flag = true;
                }
            }
            if (flag) price += 2000;
        }
        else if (caseOfThrow.size() == 3) {
            for (int i = 6; i > 0; i--) {
                if (dice[i] == 2) {
                    price = 1000 + i * 100;
                    break;
                }
            }
        }
        else {
            for (int i = 6; i > 0; i--) {
                if (dice[i] == 1) {
                    price = i * 100;
                    break;
                }
            }
        }

        maxx = max(maxx, price);
    }

    cout << maxx;

    return 0;
}