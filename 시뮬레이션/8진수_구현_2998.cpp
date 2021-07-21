#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> octal = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    while (str.length() % 3 != 0) {
        str = "0" + str;
    }

    for (int i = 0; i < str.length(); i += 3) {
        string tmp = str.substr(i, 3);

        for (int j = 0; j < 8; j++) {
            if (tmp == octal[j]) {
                cout << j;
                break;
            }
        }
    }

    return 0;
}