#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
앞에서 1~3 글자 입력되면 후보가 되는 목록이 출력되도록..
ABA TABC ARK BTS AGK ABRTC
*/

unordered_multimap<string, string> m;

int main() {

    vector<string> str = {"ABA", "TABC", "ARK", "BTS", "AGK" ,"ABRTC"};

    for (int i = 0; i < str.size(); i++) {
        string s = "";
        for (int j = 0; j < 3; j++) {
            s += str[i][j];
            m.insert({s, str[i]});
        }
    }

    string test;
    cin >> test;

    auto mi = m.equal_range(test);
    for (auto i = mi.first; i != mi.second; ++i) {
        cout << i->first << ": " << i->second << '\n';
    }

    return 0;
}