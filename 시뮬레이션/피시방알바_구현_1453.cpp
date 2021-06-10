#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[101];
    fill(arr, arr + 101, 0);

    int n;
    cin >> n;

    int cnt = 0;
    int check;
    for (int i = 0; i < n; i++) {
        cin >> check;
        if (arr[check]) cnt++;
        else arr[check]++;
    }

    cout << cnt;

    return 0;
}