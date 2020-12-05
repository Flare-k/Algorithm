#include <iostream>
using namespace std;
/*
 @+@+@....+@ = n
 n-1 + 1 = n
 n-2 + 2 = n
 n-3 + 3 = n
 D[n] = D[n-1] + D[n-2] + D[n-3]
 D[0] = 1
 */

int dp[1000];

int plus123(int n){
    if (dp[n] > 0)
        return dp[n];
    
    if (n == 1 || n == 0)
        dp[n] = 1;
    else if (n > 1){
        dp[n] = plus123(n-1) + plus123(n-2) + plus123(n-3);
    }
    
    return dp[n];
}

int main(){
    int n, iter;
    cin >> iter;

    for (int i = 0; i < iter; i++){
        cin >> n;
        cout << plus123(n) << '\n';
    }
    
    return 0;
}
