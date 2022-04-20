#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 13
using namespace std;

int T;
int plan[MAX];
int dp[MAX];
int day, month, tmonth, year;

int run() {
    fill(dp, dp + MAX, 0);

    dp[1] = min(plan[1] * day, month);
    dp[2] = min(dp[1] + plan[2] * day, dp[1] + month);

    for (int i = 3; i <= 12; i++) {
        dp[i] = min({dp[i - 1] + day * plan[i], dp[i - 1] + month, dp[i - 3] + tmonth});
    }

    dp[12] = min(dp[12], year);

    return dp[12];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;

    for (int test = 1; test <= T; test++) {
        cin >> day >> month >> tmonth >> year;

        for (int i = 1; i <= 12; i++) {
            cin >> plan[i];
        }
        
        cout << '#' << test << ' ' << run() << '\n';
    }

	return 0;
}