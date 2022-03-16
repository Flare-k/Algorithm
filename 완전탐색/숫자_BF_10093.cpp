#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long A, B;
    cin >> A >> B;

    if (A > B) swap(A, B);

    if (A != B) {
        cout << B - A - 1 << '\n';
        
        for (long long num = A + 1; num < B; num++) {
            cout << num << ' ';
        }
    }
    else {
        cout << 0 << '\n';
    }
    
    return 0;
}