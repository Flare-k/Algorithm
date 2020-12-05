#include <iostream>
using namespace std;
/*
 *Tip
 *N을 1로 만들려고 한다.
 *N을 작게 만들어야 한다.
 *3으로 나누는 것이 수를 빠르게 작게 만든다.
 *3으로 나누는 것, 2로 나누는 것, 1을 빼는 우선 순위로 N을 1로 만들어 본다.
 * D[N] = N을 1로 만드는 최소 연산 횟수.
 */
int dp[1000000];
//Top-down 방식
int makeOne(int n){
    if(n == 1)
        return 0;
    if(dp[n] >0)     //memoization //전에 문제의 정답을 구한 적이 있으면 패스
        return dp[n];
    dp[n] = makeOne(n-1) + 1;
    if(n%2 == 0){
        int temp = makeOne(n/2) + 1;
        if(dp[n] > temp)
            dp[n] = temp;
    }
    if(n%3 == 0){
        int temp = makeOne(n/3) + 1;
        if(dp[n] > temp)
            dp[n] = temp;
    }
    
    /*
     //Bottom-up 방식
    dp[1] = 0;
    for(int i=2; i<=inputNum; i++){
        dp[i] = dp[i-1]+1;
        if(i%2==0 && dp[i]>dp[i/2] + 1){
            dp[i] = dp[i/2]+1;
        }
        if(i%3==0 && dp[i]>dp[i/3] + 1){
            dp[i] = dp[i/3]+1;
        }
    }
    */
    
    
    return dp[n];
}


int main() {
    
    int n;
    cin>>n;
    cout<<makeOne(n)<<endl;
    return 0;
}
