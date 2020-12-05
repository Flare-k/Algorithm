#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    while (n--) {
        int h = 0, t = 0, check = 0, k;
        cin >> k;

        h = k / 2;
        t = k - h;

        while (h > 0) {
            for (int j = 2; j < h - 1; j++) {
                if (h % j == 0 || t % j == 0) 
                    check++;
            }

            if (check >= 1) {
                h--;
                t++;
                check = 0;
            } 
            else {
                break;
            }
        }

        cout << h << " " << t << endl;
    }

    return 0;
}