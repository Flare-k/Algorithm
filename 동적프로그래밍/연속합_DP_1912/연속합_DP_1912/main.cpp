//  연속합_DP_1912
//  Created by Flare_k on 2020/07/21.
//  Copyright © 2020 Flare_k. All rights reserved.

#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001] = {};
int arr[100001] = {};

int main(){
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }
    
    int maxNum = arr[0];
    
    for (int i = 1; i < n; i++){
        dp[i] = max(dp[i], dp[i-1] + arr[i]);
        if (dp[i] > maxNum){
            maxNum = dp[i];
    
        }
    }
    cout<<maxNum<<'\n';
}
/*
 10
 2 1 -4 3 4 -4 6 5 -5 1

 14
 */
