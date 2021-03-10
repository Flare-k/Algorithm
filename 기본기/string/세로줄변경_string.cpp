#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    string ss[5];

    for (int i = 0; i < 5; i++) {
        cin >> ss[i];
    }

    for (int i = 0; i < 5; i++) {
        swap(ss[i][1], ss[i][3]);
    }

    for (int i = 0; i < 5; i++) {
        if (ss[i] == "MAPOM") {
            cout << "yes" << '\n';
            return 0;
        }
    }

    cout << "no" << '\n';

	return 0;
}