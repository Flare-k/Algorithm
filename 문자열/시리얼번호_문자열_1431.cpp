#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int calc(string s) {
    int sum = 0;
    for (char num : s) {
        if (num >= '0' && num <= '9') sum += (num - '0');
    }

    return sum;
}

bool cmp(string A, string B) {
    if (A.length() < B.length()) return true;
    else if (A.length() > B.length()) return false;
    else {
        int aSum = calc(A);
        int bSum = calc(B);
        if (aSum != bSum) return aSum < bSum;
    }

    return A < B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> listStr;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        listStr.push_back(s);
    }

    sort(listStr.begin(), listStr.end(), cmp);

    for (string s : listStr) {
        cout << s << '\n';
    }

    return 0;
}