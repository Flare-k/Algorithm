#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int size = rocks.size();
    sort(rocks.begin(), rocks.end());
    
    int left = 0, right = distance;
    int answer = 0;

    while (left <= right) {
        int cnt = 0, prev = 0;
        int mid = (left + right) / 2;

        for (int rock : rocks) {
            if (rock - prev < mid) cnt++;
            else prev = rock;
        }

        if (distance - prev < mid) cnt++;

        if (cnt <= n) {
            answer= max(answer, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << solution(25, {2, 14, 11, 21, 17}, 2) << '\n';

    return 0;
}