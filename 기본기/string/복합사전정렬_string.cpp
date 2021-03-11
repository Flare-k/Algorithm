#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
    if (a.length() < b.length()) {
        return true;
    }
    else if (a.length() == b.length()) {
        if (a < b) {
            return true;
        }
    }
    
    return false;
}


int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0 ; i < n; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << s[i] << '\n';
    }

    return 0;
}