#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--) {
        int num;
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            cin >> num;
            if (m[num] == false) {
                m[num] = true;
            }
        }
        else if (cmd == "remove") {
            cin >> num;
            if (m[num] == true) {
                m[num] = false;
            }
        }
        else if (cmd == "check") {
            cin >> num;
            if (m[num] == true) cout << 1 << '\n'; 
            else cout << 0 << '\n';
        }
        else if (cmd == "toggle") {
            cin >> num;
            if (m[num] == true) {
                m[num] = false;
            }
            else {
                m[num] = true;
            }
        }
        else if (cmd == "all") {
            for (int i = 1; i <= 20; i++) {
                m[i] = true;
            }
        }
        else {
            for (int i = 1; i <= 20; i++) {
                m[i] = false;
            }
        }
    }

    return 0;
}