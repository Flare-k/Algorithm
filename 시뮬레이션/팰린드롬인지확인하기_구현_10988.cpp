#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;

    int s = 0, e = str.length() - 1;

    bool flag = false;

    while (s <= e) {
        if (str[s] != str[e]) {
            flag = true;
            break;
        }
        s++;
        e--;
    }

    if (flag) cout << 0;
    else cout << 1;

    return 0;
}