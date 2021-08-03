#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    ll min = 1;
    ll max = (ll)times.back() * n;  // 가장 오래걸리는 경우 long long * int
    ll answer = max;

    while (min <= max) {
        ll mid = (min + max) / 2;
        ll sum = 0;

        for (int time : times) {    // 전체 시간에서 가용 가능한 손님 수
            sum += mid / time;
        }

        if (n > sum) {
            min = mid + 1;
        }
        else {
            if (mid <= answer) answer = mid;
            max = mid - 1;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> times;
    times.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    cout << solution(m, times);

    return 0;
}