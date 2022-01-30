#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    string str;
    vector<string> v;

    for (int i = 0; i < N; i++) {
        cin >> str;

        string s = "";
        for (int j = 0; j < M; j++) {
            char ch = str[j];
            for (int k = 0; k < 2; k++) {
                s += ch;
            }
        }

        v.push_back(s);
    }

    bool flag = true;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (v[i] != s) {
            flag = false;
            break;
        }
    }

    if (flag) cout << "Eyfa" << '\n';
    else cout << "Not Eyfa" << '\n';
    
    return 0;
}