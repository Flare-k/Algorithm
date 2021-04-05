#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> mozic;

// find(찾고자하는 문자, 시작인덱스)
// substr(시작인덱스, 갯수)

int check(char s) {
    for (int i = 0; i < mozic.size(); i++) {
        if (s == mozic[i][0]) return i;
    }

    return -1;
}

string trans(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] = char(tolower(s[i]));
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    mozic.push_back("chicken");
    mozic.push_back("pizza");
    mozic.push_back("jockbal");
    mozic.push_back("bread");
    mozic.push_back("samhap");

    string s;
    cin >> s;   //HeyBread!DoYouWannaBuildAChicken

    string res = "";
    for (int i = 0; i < s.length(); i++) {
        int idx = check(char(tolower(s[i])));

        if (idx != -1) {
            string ans = s.substr(i, mozic[idx].length());
            ans = trans(ans);

            if (ans == mozic[idx]) {
                i += (mozic[idx].length() - 1);
                res += "###";
            }
            else {
                res += s[i];
            }
        }
        else {
            res += s[i];
        }
    }

    cout << res;

    return 0;
}