#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   int count = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] <= k) {
            count += (k / arr[i]);
            k %= arr[i];
        } 
        else
            continue;
    }

    cout << count << endl;
    
    return 0;
}