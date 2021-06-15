#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<string, int> person;
set<string> savePerson;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, s;
    cin >> h >> s;

    string str;
    
    for (int i = 0; i < h + s; i++) {
        cin >> str;
        person[str]++;
        savePerson.insert(str);
    }

    
    vector<string> ans;
    int cnt = 0;
    for (string idx : savePerson) {
        if (person[idx] == 2) {
            cnt++;
            ans.push_back(idx);
        }
    }

    cout << cnt << '\n';
    for (string p : ans) {
        cout << p << '\n';
    }

    return 0;
}