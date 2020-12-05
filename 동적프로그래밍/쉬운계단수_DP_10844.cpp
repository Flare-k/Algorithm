#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long dp[101][11];

/* 일단 내 방법대로 풀어보자 */
/*
 1.불가능한 경우
 2.정답을 찾은 경우
 3.다음 경우 호출
 
 dp[N][L] = dp[N - 1][L - 1] + dp[N - 1][L + 1]

 */

long go(int n){
    for (int i = 1; i <= 9; i++) {
            dp[1][i] = 1;
        }

    for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i - 1][1];
            for (int j = 1; j <= 9; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }
        }
     
    long sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[n][i];
    }

    return sum%1000000000;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cout << "N: ";
    cin >> n;
    cout << go(n) << '\n';
    
    return 0;
}

