#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> m;
int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string arabia[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

void init() {
    m["I"] = 1; m["IV"] = 4; m["V"] = 5; m["IX"] = 9;
    m["X"] = 10; m["XL"] = 40; m["L"] = 50; m["XC"] = 90;
    m["C"] = 100; m["CD"] = 400; m["D"] = 500; m["CM"] = 900;
    m["M"] = 1000;
}

int convertNum(string s) {
    int sum = 0;
    string tmp = "";

    for (int i = 0; i < s.length(); i++) {
        tmp = s[i];
        
        if (m.count(tmp + s[i + 1])) {
            sum += m[tmp + s[i + 1]];
            i++;
        }
        else {
            sum += m[tmp];
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();
    string s, e;
    cin >> s >> e;

    int sum = convertNum(s) + convertNum(e);
    cout << sum << '\n';

    int idx = 0;
    int change;
    string answer = "";

    while (sum != 0) {
        if (sum < num[idx]) {
            idx++;
            continue;
        }

        change = sum % num[idx];
        sum -= change;

        for (int i = 0; i < sum / num[idx]; i++) {
            answer += arabia[idx];
        }

        sum = change;
        idx++;
    }

    cout << answer;

    return 0;
}