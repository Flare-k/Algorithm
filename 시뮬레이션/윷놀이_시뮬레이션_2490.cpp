#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int zero = 0;
    int one = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int stick;
            cin >> stick;
            if (stick) 
                one++;
            else 
                zero++;
        }

        if (zero == 1 && one == 3) { // 도
            cout << "A" << '\n';
        }
        else if (zero == 2 && one == 2) { // 개
            cout << "B" << '\n';
        }
        else if (zero == 3 && one == 1) { // 걸
            cout << "C" << '\n';
        }
        else if (zero == 4) { // 윷
            cout << "D" << '\n';
        }
        else {  // 모
            cout << "E" << '\n';
        }

        zero = 0;
        one = 0;
    }

    return 0;
}