#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int len = str.length();

    for (int i = 0; i < len; i++) {
        cout << i << '\n';
    }

    return 0;
}