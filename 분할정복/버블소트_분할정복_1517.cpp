#include <iostream>
#include <vector>

using namespace std;


// 범위 0 ~ 1,000,000,000   -> 이중 반복문 No No
// 병합정렬을 써야할 듯

long long result = 0;

void sorting(vector<int>& arr, int start, int end) {
    int mid = (start + end) / 2;
    int left = start;
    int right = mid + 1;
    vector<int> tmp;

    if (start == end) {
        return;
    }

    sorting(arr, start, mid);
    sorting(arr, mid + 1, end);

    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            tmp.push_back(arr[left++]);
        }
        else {
            tmp.push_back(arr[right++]);
            result += (mid + 1 - left);
        }
    }

    while (left <= mid) {
        tmp.push_back(arr[left++]);
    }
    while (right <= end) {
        tmp.push_back(arr[right++]);
    }

    for (int i = start, j = 0; i <= end; i++, j++) {
        arr[i] = tmp[j];
    }

}

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

    sorting(arr, 0, n - 1);

    cout << result;

    return 0;
}