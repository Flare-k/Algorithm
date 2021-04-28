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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    int target;
    cin >> target;

    int start = 0;
    int end = arr.size() - 1;

    int sum = 0;
    int cnt = 0;

    while (1) {
        if (start >= end) break;

        sum = arr[start] + arr[end];

        if (sum < target) {
            start++;
        }
        else if (sum > target) {
            end--;
        }
        else if (sum == target) {
            cnt++;
            end--;
            start++;
        }
    }

    cout << cnt;

    return 0;
}