#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

map<string, int> m;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int cnt = 1;
    m[words[0]] = 1;    // 스타트
    
    for (int i = 1; i < words.size(); i++) {
        if (i % n == 0) cnt++;

        if (m[words[i]] == 0 && (words[i - 1].back() == words[i].front())) {
            m[words[i]]++;
        }
        else {
            return {i % n + 1, cnt};
        }

    }

    return {0, 0};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> ans = solution(2, {"hello", "one", "even", "never", "now", "world", "draw"});

    for (int a : ans) {
        cout << a << ' ';
    }

    return 0;
}