#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int term = 0;
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        term += i;
        answer += (term * 3);
    }

    cout << answer;

    return 0;
}