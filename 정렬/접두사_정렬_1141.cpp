#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool lenComp(string a, string b) {
    if (a.length() < b.length()) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> str;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        str.push_back(s);
    }

    int check[101] = {0};
    sort(str.begin(), str.end(), lenComp);  // 문자열 길이로 오름차순 정렬

    for (int i = 0; i < str.size() - 1; i++) {
        string s = str[i];
        int len = s.length();

        for (int j = i + 1; j < str.size(); j++) {
            if (s == str[j].substr(0, len)) {   // 접두어가 되는 케이스가 있다면 체크하고 break
                check[i] = 1;
                break;
            } 
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {   // check가 0인 경우는 접두사가 되지 않는 경우
        if (check[i] == 0) cnt++;
    }

    cout << cnt;

    return 0;
}