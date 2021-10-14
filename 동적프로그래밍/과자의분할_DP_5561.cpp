#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 10001;
int N;

int dp1[MAX];
int dp2[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int num;
    for (int i = 1; i < N; i++) {
        cin >> num;
        for (int j = i; j > 1; j--) {
            int a = dp1[j-1];
            int b = dp1[i+1-j] + num;
            dp2[j] = min(dp1[j-1], dp1[i-(j-1)] + num);
        }

        dp2[1] = num;
        copy(dp2, dp2 + 1 + i, dp1);
        
    }
   
    cout << dp1[N / 2];

    return 0;
}

