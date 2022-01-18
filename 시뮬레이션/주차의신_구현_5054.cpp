#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    
    vector<int> shop;

    while (T--) {
        cin >> N;

        shop.clear();
        shop.resize(N);

        for (int i = 0; i < N; i++) {
            cin >> shop[i];
        }
        
        sort(shop.begin(), shop.end());

        int sum = 0;

        for (int i = 0; i < N - 1; i++) {
            sum += (shop[i + 1] - shop[i]);
        }

        cout << sum * 2 << '\n';
    }

    return 0;
}