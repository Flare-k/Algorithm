#include <iostream>
#include <algorithm>
using namespace std;

long dp[1001][11];

/*
 1.불가능한 경우
 2.정답을 찾은 경우
 3.다음 경우 호출
 
 DP[3][7] 이라고 하면 _ _ 7 을 뜻함.
 그렇다면 2번째 자리는 어떤 숫자가 올 수 있을까?
 오르막 수 규칙에 의하면 0 ~ 7 이라는 숫자가 올 수 있다. 즉, N자리 L 숫자가 온다면, N-1자리 숫자는 0 ~ L 범위의
 숫자가 올 수 있는 것이다. 지금은 하나의 경우인 즉 L숫자를 가정했지만, 모든 경우의 수를 고려해야 하기 때문에 시그마로
 식을 세워야 한다.
 
 결국,
 DP[N][L] = DP[N-1][0] + DP[N-1][1] + DP[N-1][2] +  . . . .  + DP[N-1][L] 인 것
 
 n = 2인 경우,
 11 ~ 19
 22 ~ 29
 33 ~ 39
 .
 .
 .
 
https://limkydev.tistory.com/113 참고..!
 */

long go(int n){
    /* 한 자리수의 경우 */
    for (int i = 0; i <= 9; i++) {
            dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }
     
    long sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[n][i];
    }

    return sum%10007;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    //cout<<"N: ";
    cin >> n;
    cout << go(n) << '\n';
    
    return 0;
}

