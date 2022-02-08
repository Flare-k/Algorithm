#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define MAX 3
using namespace std;

vector<string> str;
map<string, int> m;
map<string, int> m_cpy;
string puzzle[MAX];
vector<string> tmp;

bool run() {
    for (int i = 0; i < 3; i++) {
        m[puzzle[i]]--;
    }

    for (int i = 0; i < 3; i++) {
        string t = "";
        for (int j = 0; j < 3; j++) {
            t += puzzle[j][i];
        }

        if (m[t] == 0) return false;
        
        m[t]--;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;

    for (int i = 0; i < MAX * 2; i++) {
        cin >> s;
        m[s]++;
        str.push_back(s);
    }

    m_cpy = m;

    sort(str.begin(), str.end());

    do {

        for (int i = 0; i < 3; i++) {
            puzzle[i] = str[i];
        }

        if (run()) {
            m = m_cpy;
            string ans = "";
            
            for (int i = 0; i < 3; i++) {
                ans += puzzle[i];
            }

            tmp.push_back(ans);
        }

    } while (next_permutation(str.begin(), str.end()));

    int size = tmp.size();

    if (size > 0) {
        sort(tmp.begin(), tmp.end());
        string answer = tmp.front();

        for (int i = 0; i < 9; i++) {
            cout << answer[i];
            if (i % 3 == 2) cout << '\n';
        }
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}