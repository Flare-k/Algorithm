#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

unordered_map<string, int> m;

bool solution(vector<string> phone_book) {
    
    for (string phone : phone_book) {
        m[phone] = 1;
    }

    for (int i = 0; i < phone_book.size(); i++) {
        string tmp = "";

        for (int j = 0; j < phone_book[i].length(); j++) {
            tmp += phone_book[i][j];
            if (m[tmp] && tmp != phone_book[i]) return false;
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