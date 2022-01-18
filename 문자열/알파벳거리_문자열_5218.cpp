#include <iostream>
#include <string>
using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while (T--) {
        string x, y;
        cin >> x >> y;

        string dist = "";

        int size = x.length();

        for (int i = 0; i < size; i++) {
            if (x[i] <= y[i]) dist += (to_string(y[i] - x[i]) + " ");
            else dist += (to_string(y[i] - x[i] + 26) + " ");
        }

        cout << "Distances: " << dist << '\n';
    }

    return 0;
}