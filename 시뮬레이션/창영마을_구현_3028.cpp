#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cup[3] = {1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string turn;
    cin >> turn;

    for (char ch : turn) {
        if (ch == 'A') {
            swap(cup[0], cup[1]);
        }
        else if (ch == 'B') {
            swap(cup[1], cup[2]);
        }
        else {
            swap(cup[0], cup[2]);
        }
    }

    for (int i = 0; i < 3; i++) {
        if (cup[i] == 1) cout << i + 1;
    }

    return 0;
}