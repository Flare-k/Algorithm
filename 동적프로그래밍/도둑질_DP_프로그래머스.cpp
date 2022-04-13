#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

int dp[MAX];    // i번째 도둑질 할 때 최대 돈의 양
/*
-> 1 2 3 4 5
-> O X O X X
-> X O X O X
*/
int solution(vector<int> money) {
    int answer = 0;
    
    dp[0] = money[0];
    dp[1] = money[0];   // 0번째를 털었을때의 최대값고 같아야 함

    for (int i = 2; i < money.size() - 1; i++) {
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }

    answer = max(answer, *max_element(dp, dp + MAX));

    // 반대 방향
    fill(dp, dp + MAX, 0);
    reverse(money.begin(), money.end());

    dp[0] = money[0];
    dp[1] = money[0];

    for (int i = 2; i < money.size() - 1; i++) {
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }

    answer = max(answer, *max_element(dp, dp + MAX));

    return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cout << solution({1, 2, 3, 1}) << '\n';

    return 0;
}