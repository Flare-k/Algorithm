#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

// 사실상 중앙값 구하기 문제나 다름없다.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    cout << arr[(n - 1) / 2];

    return 0;
}