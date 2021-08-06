#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

// 같거나, 한문자를 빼거나 더하거나, 바꾸거나

int alpha[30];
int cmp[30];
int n, total;
string target;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> target;

    n -= 1;

    for (char tc : target) {
        int idx = tc - 65;
        ++alpha[idx];
    }

    while (n--) {
        memset(cmp, 0, sizeof(cmp));
        bool flag = false;
        int a = 0, b = 0;
        string s;

        cin >> s;

        for (char sc : s) {
            int idx = sc - 65;
            ++cmp[idx];
        }

        for (int i = 0; i < 26; i++) {
            if (alpha[i] == cmp[i]) continue;

            if (abs(alpha[i] - cmp[i]) > 1) {
                flag = true;
                break;
            }
            else if (alpha[i] < cmp[i]) a++;
            else if (alpha[i] > cmp[i]) b++;

            if (a > 1 or b > 1) {
                flag = true;
                break;
            }
        }

        if (flag) continue;

        total++;       
    }

    cout << total;

    return 0;
}