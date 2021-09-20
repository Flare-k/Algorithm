#include <iostream>
#include <string>
using namespace std;

string passwd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> passwd;

    for (char ch : passwd) {
        ch = ch - 3;
        if (ch < 65) ch += 26;
        cout << ch;
    }

    return 0;
}