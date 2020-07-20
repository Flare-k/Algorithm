#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000] = {};
int arr[1000] = {};

int main(){
    int n;
    int sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++){
        dp[i] = 1;

        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        sum = max(sum, dp[i]);
    }
    cout << sum << endl;
}
/*
 10
 10 20 25 11 30 15 17 18 50 19
 */
