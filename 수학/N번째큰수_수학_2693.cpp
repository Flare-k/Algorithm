#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int arr[10];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        fill(arr, arr + 10, 0);
        for (int j = 0; j < 10; j++) {
            cin >> arr[j];
        }

        sort(arr, arr + 10, greater<int>());

        result.push_back(arr[2]);
    }

    for (int num : result) {
        cout << num << '\n';
    }
    
    return 0;
}