#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    sort(str.begin(), str.end());

    do {
        bool check = true;
        for (int i = 0; i < str.length() - 1; i++) {
            if (str[i] == str[i + 1]) {
                check = false;
                break;
            }
        }

        if (check) cnt++;

    } while (next_permutation(str.begin(), str.end()));


    cout << cnt;

    return 0;
}