#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long dp[987654321];

/* 일단 내 방법대로 풀어보자 */
/*
 1.불가능한 경우
 2.정답을 찾은 경우
 3.다음 경우 호출
 
 내가 생각한 이친수는.. 곧 피보나치였다.
 */

long long go(int n){
    if(dp[n] > 0)
        return dp[n];
    dp[1] = 1;
    dp[2] = 1;
    
    if(n > 2){
        dp[n] = go(n-1) + go(n-2);
    }

    return dp[n];
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

