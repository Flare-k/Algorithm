#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <utility>
#define INF 987654321

using namespace std;

// 가장 가까운 두점의 거리의 제곱을 출력한다.
// https://www.crocus.co.kr/807 이 블로그를 참고하였고 이해하는데에 중점을 두었다ㅠㅠㅠ

map<pair<int, int>, int> m;

double getDist(pair<int, int> a, pair<int, int> b) {
    int x = a.first - b.first;
    int y = a.second - b.second;

    return (double)(x * x + y * y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end());

    m[{arr[0].second, arr[0].first}] = 1;
    m[{arr[1].second, arr[1].first}] = 1;

    double ans = getDist(arr[0], arr[1]);

    int last = 0;

    for (int i = 2; i < n; i++) {
       // while문은 최솟값보다 x간의 거리가 더 큰 것을 제거하는 과정
       // x간의 거리가 최솟값 보다 더 크면 y값을 비교할 필요가 없다.
        while (last < i) {
            int dx = arr[i].first - arr[last].first;

            if (dx * dx <= ans) break;

            m.erase({arr[last].second, arr[last].first});
            last++;
        }
        // ans의 실제거리
        int limit = sqrt(ans);

        auto low = m.lower_bound({arr[i].second - limit, -INF});
        auto up = m.upper_bound({arr[i].second + limit, INF});

        for (auto iter = low; iter != up; iter++) {
            ans = min(ans,
                        getDist({iter->first.second, iter->first.first}, arr[i]));
        }

        m[{arr[i].second, arr[i].first}] = 1;
    }

    cout << (int)ans;

    return 0;
}