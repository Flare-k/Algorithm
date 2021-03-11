#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int P, N;
    cin >> P >> N;

    string tmp = "";

    while (N--) {

        P *= 2;
        tmp = to_string(P);

        string conv = "";
        for (int i = tmp.length() - 1; i >= 0; i--) {
            conv += tmp[i];
        }

        P = stoi(conv);

    }

    cout << P << '\n';

    return 0;
}