#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

int main() {

    string mos[5] = {"1011",
                    "0011",
                    "1111",
                    "0000",
                    "1100"};

    for (int i = 0; i < 5; i++) {
        string mosSignal;
        cin >> mosSignal;
        for (int j = 0; j < 2; j++) {
            m[mosSignal.substr(j, 4)]++;
        }
    }

    bool flag = false;
    for (int i = 0; i < 5; i++) {
        if (m.count(mos[i])) flag = true;
    }

    if (flag) cout << "yes";
    else cout << "no";

    return 0;
}