#include <iostream>
#include <vector>
#include <cmath>
#define WON 10000
using namespace std;

vector<int> festival1 = {500, 300, 200, 50, 30, 10};
vector<int> festival2 = {512, 256, 128, 64, 32};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int a, b, sum = 0;
        
        cin >> a >> b;
        
        int gap = 0, idx = 0;
        
        for (int i = 1; i <= 21; i += gap) {
            if (a >= i && a <= (i + gap)) {
                sum += festival1[idx];
                break;
            }

            idx++;
            gap++;
        }

        idx = 0;

        for (int i = 0; i <= 4; i++) {
            int s = pow(2, i);
            int e = pow(2, i + 1);

            if (b >= s && b < e) {
                sum += festival2[idx];
                break;
            }
            
            idx++;
        }

        cout << sum * WON << '\n';
    }

    return 0;
}