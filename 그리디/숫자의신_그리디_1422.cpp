#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int N, K;
vector<string> v;

bool cmp(string a, string b) {
    if (a + b > b + a) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> N;

    string str;
    ll tmp = 0;

    for (int i = 0; i < K; i++) {
        cin >> str;
        tmp = max(tmp, stoll(str));
        v.push_back(str);
    }

    for (int i = 0; i < N - K; i++) {
        v.push_back(to_string(tmp));
    }

    sort(v.begin(), v.end(), cmp);

    for (auto s : v) {
        cout << s;
    }

    return 0;
}