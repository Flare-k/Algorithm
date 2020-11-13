#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> dp[1000001];

void makeOne(int n){
    dp[1] = {0, 0}; // 경로의 수, 다음 경로

    for (int i = 2; i <= n; i++){
        dp[i] = {dp[i - 1].first + 1, i - 1};
        if (i % 2 == 0){
            if (dp[i].first > dp[i / 2].first + 1)
                dp[i] = {dp[i / 2].first + 1, i / 2};
        }
        if (i % 3 == 0) {
            if (dp[i].first > dp[i / 3].first + 1)
                dp[i] = {dp[i / 3].first + 1, i / 3};
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    makeOne(n);
    
    cout << dp[n].first << '\n';

    int i = n;
    cout << i << " ";
    while (dp[i].second != 0){
        cout << dp[i].second << " ";
        i = dp[i].second;
    }

    return 0;
}