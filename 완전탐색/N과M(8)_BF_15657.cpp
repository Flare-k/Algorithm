#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10000 + 1;
int arr[MAX]; 
int result[MAX];
int n, m;

void go(int idx, int start) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) {
        result[idx] = arr[i - 1];
        go(idx + 1, i);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    go(0, 1);
    
    return 0;
}
