#include <iostream>
#include <string>
using namespace std;

int main() {

    int n;
    cin >> n;

    int idx = 1;

    while (n--) {
        string str;
        cin >> str;

        cout << "String #" << idx++ << '\n';

        for (int i = 0; i < str.length(); i++) {
            if (str[i] !=  'Z') str[i] = char(str[i] + 1);
            else str[i] = 'A';
        }

        cout << str << "\n\n";
    }

    return 0;
}