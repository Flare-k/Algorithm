#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

map<char, string> m;

void init() {
    m['A'] = "000000";
    m['B'] = "001111";
    m['C'] = "010011";
    m['D'] = "011100";
    m['E'] = "100110";
    m['F'] = "101001";
    m['G'] = "110101";
    m['H'] = "111010";
}

char check(string target) {
    for (char ch = 'A'; ch <= 'H'; ch++) {
        string s = m[ch];
        
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != target[i]) cnt++;
        }
        if (cnt <= 1) return ch;
    }

    return '0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    init();

    string str;
    cin >> str;

    int idx = 1;
    bool flag = false;
    string answer = "";
    for (int i = 0; i < str.length(); i += 6) {
        char ch = check(str.substr(i, i + 6));

        if (ch != '0') answer += ch;
        else {
            cout << idx;
            flag = true;
            break;
        }
        idx++;
    }

    if (!flag) cout << answer;

    return 0;
}
