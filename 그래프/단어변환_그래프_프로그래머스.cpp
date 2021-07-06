#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int result = 21e8;
bool used[51];

int checkStr(string a, string b) {
    int cnt = 0;
    int len = a.length();

    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) cnt++;
    }
    return cnt;
}

void run(string begin, string target, vector<string>& words, int level) {
    if (begin == target) {
        result = min(result, level);
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        int dif = checkStr(begin, words[i]);

        if (dif == 1) {
            if (!used[i]) {
                used[i] = true;
                run(words[i], target, words, level + 1);
                used[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    run(begin, target, words, 0);

    if (result != 21e8) answer = result;
    else answer = 0;

    return answer;
}

int main() {
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << '\n';
    // cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << '\n';

    return 0;
}