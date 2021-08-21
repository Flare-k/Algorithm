#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char str[5][16];
int maxx = -21e8;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(str, ' ', sizeof(str));

    for (int i = 0 ; i < 5; i++) {
        cin >> s;
        int len = s.length();
        maxx = max(maxx, len);

        for (int j = 0 ; j < len; j++) {
            str[i][j] = s[j];
        }   
    }

    for (int i = 0 ; i < maxx; i++) {
        for (int j = 0 ; j < 5; j++) {
            if (str[j][i] != ' ') cout << str[j][i];
        }   
    }

    return 0;
}