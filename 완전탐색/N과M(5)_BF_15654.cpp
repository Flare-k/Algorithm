#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
bool check[MAX]; 
int arr[MAX];
int result[MAX];

void go(int index, int n, int m) {
    if (index == m) {
        for(int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!check[i - 1]) {
            check[i - 1] = true;
            result[index] = arr[i - 1];

            go(index + 1, n, m);
            check[i - 1] = false;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    
    go(0, n, m);
    
    return 0;
}
