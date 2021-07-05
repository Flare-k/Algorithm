#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string target = "BOBOOBOBOBOBBM";

    int n;
    cin >> n;

    for (int i = 0; i < target.length() - 2; i++) {
        string tmp = target.substr(i, 3);
        um[tmp]++;
    }

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        if (um.count(input)) cout << um[input] << '\n';
    }

    return 0;
}