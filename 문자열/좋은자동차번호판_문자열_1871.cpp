#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    while (n--) {

        string board;
        cin >> board;

        string frontStr = board.substr(0, 3);
        string backStr = board.substr(4);

        int num26 = 1;
        int idx = 0;
        reverse(frontStr.begin(), frontStr.end());

        int strSum = 0;

        while (idx <= frontStr.length() - 1) {
            strSum += ((frontStr[idx++] - 'A') * num26);
            num26 *= 26;
        }

        int numSum = stoi(backStr);

        if (abs(strSum - numSum) <= 100) cout << "nice" << '\n';
        else cout << "not nice" << '\n';
    }

    return 0;
}