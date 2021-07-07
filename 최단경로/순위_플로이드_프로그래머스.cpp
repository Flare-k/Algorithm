#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
플로이드 워셜로 풀릴거라고 전혀 예상 못했다..
*/

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<bool>> game(n + 1, vector<bool>(n + 1, false));

    for (auto r : results) {
        int win = r[0];
        int lose = r[1];
        game[win][lose] = true;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (game[i][k] && game[k][j]) {   // a가 b를 이기고, b가 c를 이긴다면.. a가 c를 이긴다.
                    game[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (size_t j = 1; j <= n; j++) {
            if (game[i][j] || game[j][i]) cnt++;  // i 번째가 이기거나 진 경우
        }
        if (cnt == n - 1) answer++;
    }

    return answer;
}

int main() {
    int ans = solution(5,{
                            {4, 3},
                            {4, 2},
                            {3, 2},
                            {1, 2},
                            {2, 5},});

    cout << ans;

    return 0;
}