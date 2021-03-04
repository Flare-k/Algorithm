#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.top() < K && pq.size() > 1) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        pq.push(a + (2 * b));
        answer++;

    }

    if (pq.size() == 1 && pq.top() < K) {
            answer = -1;
    }

    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution({1, 2, 3, 9, 10, 12}, 7) << '\n'

    return 0;
}