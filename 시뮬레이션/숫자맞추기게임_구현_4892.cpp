#include <iostream>

using namespace std;

int num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int idx = 1;
    while (1) {
        cin >> num;

        if (num == 0) break;

        int tmp;
        
        num *= 3;
        tmp = num;

        if (num % 2 == 1) {
            num = (num + 1) / 2;
        }
        else {
            num /= 2;
        }

        num *= 3;

        if (tmp % 2 == 1) cout << idx++ << ". odd " << num / 9 << '\n';
        else cout << idx++ << ". even " << num / 9 << '\n';
    }

    return 0;
}