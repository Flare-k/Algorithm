#include <iostream>
#include <string>
using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += j;
            if (sum == n) {
                cnt++;
                break;
            }
            else if (sum > n) break;
        }
    }

    return cnt;
}

int main() {
    int ans = solution(15);
    cout << ans;
    return 0;
}