#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 처음에 map으로 A+B, C+D를 구해 구현해봤으나 시간초과ㅠㅠ

int n;
long long arr[4001][4];
vector<long long> a;
vector<long long> b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a.push_back(arr[i][0] + arr[j][1]);
            b.push_back(arr[i][2] + arr[j][3]);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long cnt = 0;
    for (long long num : a) {
        // 같은 수가 여러 개 있을 수 있으므로 "찾고자하는 수보다 큰 수의 인덱스 - 찾고자하는 수의 인덱스"를 하면 몇개인지 구할 수 있다.
        int start = lower_bound(b.begin(), b.end(), -num) - b.begin();
        int end = upper_bound(b.begin(), b.end(), -num) - b.begin();

        cnt += (end - start);
    }

    cout << cnt;

    return 0;
}