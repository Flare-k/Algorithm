#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            cout << ' ';
        }

        for (int k = 0; k < i; k++) {
            cout << '#';
        }
        cout << '\n';
    }
}