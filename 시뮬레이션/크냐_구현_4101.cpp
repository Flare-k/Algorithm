#include <iostream>
using namespace std;

int A, B;

int main() {

    while (1) {
        cin >> A >> B;

        if (A == 0 && B == 0) break;

        if (A > B)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }

    return 0;
}