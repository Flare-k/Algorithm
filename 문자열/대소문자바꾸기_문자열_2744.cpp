#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z') cout << char(ch - 32);
        else if (ch >= 'A' && ch <= 'Z') cout << char(ch + 32);
    }

    return 0;
}