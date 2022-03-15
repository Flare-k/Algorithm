#include <iostream>
#include <string>
using namespace std;

string str, bomb, stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str >> bomb;

    int bomblength = bomb.length();

    for (int i = 0; i < str.length(); i++) {
        stk += str[i];
        
        if (stk.back() == bomb.back()) {
            int stklength = stk.length();
            int idx = bomb.length() - 1;
            int cnt = 0;

            if (stklength >= bomblength) {
                for (int j = stklength - 1; j >= stklength - bomblength; j--) {
                    if (stk[j] == bomb[idx--]) cnt++;
                }

                if (cnt == bomblength) {
                    while (cnt--) {
                        stk.pop_back();
                    }
                }
            }
        }
    }

    if (stk.length() > 0) cout << stk << '\n';
    else cout << "FRULA" << '\n';

    return 0;
}