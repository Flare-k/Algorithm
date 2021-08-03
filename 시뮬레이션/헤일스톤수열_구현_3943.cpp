#include <iostream>
using namespace std;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        int num;
        cin >> num;
        
        int maxx = num;

        while (num != 1) {
            if (num % 2 == 0) num /= 2;
            else num = num * 3 + 1;
            maxx = max(maxx, num);
        }

        cout << maxx << '\n';
    }

    return 0;
}