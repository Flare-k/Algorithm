#include <iostream>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    int minNum = 987654321;
    int num;
    int sum = 0;

    for (int i = 0; i < 7; i++) {
        cin >> num;
        if (num > 0 && num % 2 == 1) {
            sum += num;
            if (num < minNum) {
                minNum = num;
            }
        }
    }

    if (minNum == 987654321) {
        cout << -1;
    }
    else {
        cout << sum << '\n' << minNum;
    }

    return 0;
}