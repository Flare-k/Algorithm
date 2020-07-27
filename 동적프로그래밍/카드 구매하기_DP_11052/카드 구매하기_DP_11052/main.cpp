#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int dp[100001] = {};
int p[100001] = {};

int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], p[j] + dp[i-j]);
        }
    }
    cout<<dp[n]<<endl;
    
    return 0;
}
