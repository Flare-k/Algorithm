#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += (arr[i] + arr[0]);
    }

    cout << sum;


    return 0;
}