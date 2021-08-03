#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int num;
    while (1) {
        cin >> num;

        if (num == 0) break;

        if (num % n == 0) {
            cout << num << " is a multiple of " << n << ".\n";
        }
        else {
            cout << num << " is NOT a multiple of " << n << ".\n";
        }
    }

    return 0;
}