#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    int dist;

    while (1) {
        cin >> num;

        if (num == "0") break;

        dist = num.length() + 1;

        for (char n : num) {
            if (n == '1') dist += 2;
            else if (n == '0') dist += 4;
            else dist += 3;
        }

        cout << dist << '\n';
        dist = 0;
    }

    return 0;
}