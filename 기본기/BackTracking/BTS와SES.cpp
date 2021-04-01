#include <iostream>
#include <string>
using namespace std;

string words[5] = {"BTS", "SBS", "BS", "CBS", "SES"};


void run(int cnt, string& ans, string input) {
    if (ans.length() > input.length()) return;
    
    if (ans == input) {
        cout << cnt;
        return;
    }

    for (int i = 0; i < 5; i++) {
        string tmp = ans;
        ans += words[i];
        run(cnt + 1, ans, input);
        ans = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    string ans = "";

    run(0, ans, input);

    return 0;
}