#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int dp[100001], maxWine[100001], n, m;

int max(int a, int b, int c) {
    return a > b ? (a > c) ? a : c : (b > c) ? b : c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for(int i = 1; i <= n; i++) {
        cin>>maxWine[i];
    }
    
    dp[1] = maxWine[1];
    
    if(n > 1){
        dp[2] = maxWine[1] + maxWine[2];
    }
    if(n > 2){
        for(int i = 3; i <= n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + maxWine[i], dp[i - 3] + maxWine[i - 1] + maxWine[i]);
        }
    }
    cout<<dp[n]<<'\n';
    
    return 0;
}

/*
 6
 6
 10
 13
 9
 8
 1
 */
