#include <iostream>
using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    
    int x = 1;

    while(T--) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << (x++) << ": " << a + b << '\n';
    }

    return 0;
}