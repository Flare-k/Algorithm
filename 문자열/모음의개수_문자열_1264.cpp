#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        string str;
        getline(cin, str);

        if (str == "#") break;

        int cnt = 0;

        for (char s : str) {
            if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}