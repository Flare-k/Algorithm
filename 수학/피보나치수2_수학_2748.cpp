#include <iostream>
using namespace std;

long long arr[91];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    arr[0] = 0;
    arr[1] = 1;

    int n;
    cin >> n;
    
    for (int i = 2; i < 91; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[n];

    return 0;
}