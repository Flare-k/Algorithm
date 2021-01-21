#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/**
 * 스위핑 알고리즘
 * = 어떤 선이나 공간을 한쪽에서부터 싹 쓸어버리는 것
 * 한 번만 전체 공간을 스캔하면서 마주치는 요소들에 대해 뭔가를 해주면 정답이 구해진다.
 * 
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());

    int result = 0;
    int a = -1e9, b = -1e9;

    for (int i = 0; i < n; i++) {
        // 만약 a의 값이 이전 b값보다 크면 
        if (b < arr[i].first) {
            result += (b - a);
            a = arr[i].first;
            b = arr[i].second;
        }
        else {
            b = max(b, arr[i].second);
        }
    }
    result += (b - a);

    cout << result;

    return 0;
}