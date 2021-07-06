#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    for (int i = 0; i < clothes.size(); i++) {
        string type = clothes[i][1];
        m[type]++;
    }

    for (auto i = m.begin(); i != m.end(); ++i) {
        answer *= (i->second + 1);
    }

    return answer - 1;
}

int main() {
    int ans = solution({
        {"a", "aa"},
        {"b", "aa"},
        {"c", "aa"},

        {"aa", "bb"},
        {"bb", "bb"},
        {"cc", "bb"},
        
        {"aaa", "cc"},
        {"bbb", "cc"},
        {"ccc", "cc"},
    });

    cout << ans;

    return 0;
}