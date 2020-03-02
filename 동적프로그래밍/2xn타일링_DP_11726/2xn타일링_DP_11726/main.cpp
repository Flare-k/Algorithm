/*
 2xn 직사각형을 1x2 2x1 타일로 채우는 방법의 수
 D[n] = 2xn 직사각형을 채우는 방법의 수
 
 가장 오른쪽에 타일을 놓을 수 있는 방법은 총 2가지가 있다.
 2x1 1개 or 1x2 2개  => 경우의 수: D[n-1]   or   경우의 수 : D[n-2]
 D[n] = D[n-1] + D[n-2]
 */
#include <iostream>
using namespace std;

int dp[1000];

int tile(int n){
    if(dp[n] > 0)     //memoization //전에 문제의 정답을 구한 적이 있으면 패스
        return dp[n];
    
    if(n == 0 || n == 1)
        dp[n] = 1;
    
    if(n>=2 && n<=1000){
        dp[n] = tile(n-1) + tile(n-2);
    }
    
    return dp[n]%10007;
}

int main() {
    int n;
    cin>>n;
    cout<<tile(n)<<'\n';
    return 0;
}
