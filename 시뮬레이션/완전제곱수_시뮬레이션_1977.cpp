#include <iostream>
#include <cmath>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    int a, b;
    cin >> a >> b;

    int sum = 0;
    int minNum = 987654321;

    for (int i = 0; i < 101; i++) {
        int sqr = i * i;
        if (a <= sqr && sqr <= b) {
            sum += sqr;
            if (sqr < minNum) {
                minNum = sqr;
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