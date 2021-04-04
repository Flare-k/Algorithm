#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string aqua;
    cin >> aqua;

    int maxLen = -21e8;
    int cnt = 0;

    for (int i = 0; i < aqua.length(); i++) {
        if (aqua[i] == '~') {
            cnt++;
        }
        else {
            if (maxLen < cnt) maxLen = cnt;
            cnt = 0;
        }
    }

    for (int i = 0; i < maxLen; i++) {
        cout << "~";
    }
    
    return 0;
}