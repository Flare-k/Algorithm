#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/* 일단 내 방법대로 풀어보자 */
/*
 1.불가능한 경우
 2.정답을 찾은 경우
 3.다음 경우 호출
 */

int dp[2][100001], ans[2][100001], n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    while (n--){
        cin >> m;
        
        for (int i = 0; i < 2; i++){
            for (int j = 1; j <= m; j++){
                cin>>ans[i][j];
            }
        }
        // dp[0][0] = dp[1][0] = 0;
        dp[0][1] = ans[0][1];
        dp[1][1] = ans[1][1];
        
        for (int i = 2; i <= m; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + ans[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + ans[1][i];
        }

        cout << max(dp[0][m], dp[1][m]) << '\n';;
    }
    
    return 0;
}
