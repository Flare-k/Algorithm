//  가장 긴 바이토닉 부분 수열 분류_DP_11054 가장긴바이토닉부분수열분류
//  Copyright © 2020 Flare_k. All rights reserved.

#include <iostream>
#include <algorithm>

using namespace std;

int dpL[1001] = {};
int dpR[1001] = {};
int arr[1001] = {};

int main(){
    int n;
    int sumL = 0;
    int sumR = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        dpL[i] = 1;

        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j]){
                dpL[i] = max(dpL[i], dpL[j] + 1);
            }
        }
        sumL = max(sumL, dpL[i]);
    }

    for (int i=n-1; i>=0 ;i--){
        dpR[i] = 1;
        for(int j=n-1; j>=i; j--){
            if (arr[i] > arr[j]){
                dpR[i] = max(dpR[i], dpR[j] + 1);
            }
        }
        sumR = max(sumR, dpR[i]);
    }

    int ans = dpL[0] + dpR[0];
    for(int i=1; i<n; i++){
        if(ans < dpL[i] + dpR[i])
            ans = dpL[i] + dpR[i];
    }
    cout<<ans-1<<'\n';
}
/*
 10
 1 100 2 50 60 3 5 6 7 8
 
 113
 
 */
