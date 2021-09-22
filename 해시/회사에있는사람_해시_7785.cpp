#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, string> um;
vector<string> answer;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    string name, el;
    for (int i = 0; i < n; i++) {
        cin >> name >> el;

        um[name] = el;
    }

    for (auto iter = um.begin(); iter != um.end(); iter++) {
        if (iter->second == "enter") answer.push_back(iter->first);
    }

    sort(answer.rbegin(), answer.rend());

    for (string name : answer) {
        cout << name << '\n';
    }
    
    return 0;
}