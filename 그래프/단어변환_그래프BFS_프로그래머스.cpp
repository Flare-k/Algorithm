#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int result = 21e8;
bool used[51];

struct Node {
    string word;
    int level;
};

int checkStr(string a, string b) {
    int cnt = 0;
    int len = a.length();

    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) cnt++;
    }
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    queue<Node> q;

    q.push({begin, 0});
    int idx = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.word == target) {
            answer = now.level;
            break;
        }

        for (int i = 0; i < words.size(); i++) {
            if (used[i]) continue;
            if (checkStr(now.word, words[i]) == 1) {
                used[i] = true;
                q.push({words[i], now.level + 1});
            }

        }
    }

    return answer;
}

int main() {
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << '\n';
    // cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << '\n';

    return 0;
}