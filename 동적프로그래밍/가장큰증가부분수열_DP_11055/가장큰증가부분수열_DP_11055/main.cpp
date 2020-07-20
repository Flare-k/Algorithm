#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001] = {};
int arr[1001] = {};

int main(){
    int n;
    int sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i] = arr[i];

        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j]){
                dp[i] = max(dp[i],dp[j] + arr[i]);
            }
        }
        sum = max(sum, dp[i]);
    }
    cout << sum << endl;
    
}
/*
 10
 1 100 2 50 60 3 5 6 7 8
 
 113
 
 */
