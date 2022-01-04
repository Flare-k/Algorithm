#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

unordered_map<string, int> m;

bool solution(vector<string> phone_book) {
    
    for (string phone_number : phone_book) {
        m[phone_number] = true;
    }

    for (string phone_number : phone_book) {
        string tmp = "";
        for (char ch : phone_number) {
            tmp += ch;

            if (m.count(tmp) && tmp != phone_number) return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    bool ans = solution({"111113", "1112", "12"});

    cout << ans;

    return 0;
}