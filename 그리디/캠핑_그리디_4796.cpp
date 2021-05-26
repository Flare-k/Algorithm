#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int L, P, V;
    
    int idx = 1;
    while (1) {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;

        int ans = 0;
        ans = (V / P) * L + min((V % P), L);

        cout << "Case " << idx++ << ": " << ans << '\n';
    }

    return 0;
}