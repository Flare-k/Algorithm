#include <iostream>
using namespace std;

int coins[4] = {500, 100, 50, 10};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int total;
    cin >> total;

    int answer = 0;
    int i = 0;

    while (total != 0) {
        if (total / coins[i] != 0) {
            answer += (total / coins[i]);
        }

        total %= coins[i];
        i++;
    }

    cout << answer;

    return 0;
}