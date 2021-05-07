#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool check[10];
int usrLen, banLen;
set<string> ans;

void run(int level, string res, vector<string>& user_id, vector<string>& banned_id) {
    // 종료조건
    if (level == banLen) {
        sort(res.begin(), res.end());
        ans.insert(res);
        return;
    }

    string banUsr = banned_id[level];

    for (int i = 0; i < usrLen; i++) {
        string usr = user_id[i];

        if (banUsr.length() != usr.length()) continue;
        if (check[i]) continue;

        bool possible = true;
        for (int i = 0; i < banUsr.length(); i++) {
            if (banUsr[i] == '*') continue;
            if (usr[i] != banUsr[i]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            check[i] = true;
            run(level + 1, res + to_string(i), user_id, banned_id);
            check[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    usrLen = user_id.size();
    banLen = banned_id.size();
    
    run(0, "", user_id, banned_id);

    return ans.size();
}

int main() {

    //cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "abc1**"});         // 2
    //cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"*rodo", "*rodo", "******"});// 2
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "*rodo", "******", "******"});  // 3

    return 0;
}