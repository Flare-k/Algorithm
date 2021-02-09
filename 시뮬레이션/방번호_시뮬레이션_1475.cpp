#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string roomNumber;
    cin >> roomNumber;

    int use[10];
    fill(use, use + 10, 0);

    for (int i = 0; i < roomNumber.length(); i++) {
        use[roomNumber[i] - '0']++;
    }

    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (i != 9 && i != 6) {
            cnt = max(cnt, use[i]);
        }
    }

    cout << max(cnt, (use[6] + use[9] + 1) / 2);

    return 0;

}