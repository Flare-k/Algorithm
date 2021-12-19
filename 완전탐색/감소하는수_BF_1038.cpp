#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> ans;
bool check[10];

bool cmpStr(string a, string b) {
    if (a.length() < b.length()) return true;
    else if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == b[i]) continue;
            return a[i] < b[i] ? true : false;
        }
    }

    return false;
}

void run(int start) {
    string s = "";

    for (int i = 9; i >= 0; i--) {
        if (check[i]) s += ('0' + i);
    }

    ans.push_back(s);

    for (int i = start; i < 10; i++) {
        if (!check[i]) {
            check[i] = true;
            run(i + 1);
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n > 1022) cout << -1;
    else {
        fill(check, check +! 10, false);
        run(0);
        sort(ans.begin(), ans.end(), cmpStr);
        cout << ans[n + 1];
    }
    
    return 0;
}