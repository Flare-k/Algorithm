#include <iostream>
using namespace std;

int main() {

    int testCase;
    cin >> testCase;

    while (testCase--) {
        int num;
        cin >> num;
        
        int cnt = 0;

        while (num != 0) {
            int tmp = num % 2;
            num /= 2;

            if (tmp == 1) cout << cnt << ' ';
            cnt++;
        }
        cout << '\n';
    }

    return 0;
}