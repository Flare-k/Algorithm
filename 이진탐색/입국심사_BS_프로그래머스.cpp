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

    long long answer = solution(6, {7, 10});
    cout << answer << '\n';

    return 0;
}