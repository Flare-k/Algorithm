#include <iostream>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    int day;
    cin >> day;

    int cnt = 0;
    int car;
    for (int i = 0; i < 5; i++) {
        cin >> car;
        if (car == day) 
            cnt++;
    }

    cout << cnt;

    return 0;
}