#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int dp[n];
    int p[n];
    for(int i=0; i <n; i++){
        dp[i] = -1;
        p[i] = -1;
    }   //dp 초기화
    
    for(int i=0; i<=n; i++){
        for(int j=i; j<=n; j++){
            dp[n] = max(dp[n], dp[n-i] + p[i]);
        }
    }
    
    return 0;
}
