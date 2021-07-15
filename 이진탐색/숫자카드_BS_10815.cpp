#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;

bool binarySearch(int n) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == n) return true;

        if (arr[mid] > n) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        cout << binarySearch(num) << ' ';
    }

    return 0;
}