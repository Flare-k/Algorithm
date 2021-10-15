#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

char vowel[5] = {'A', 'E', 'I', 'O', 'U'};
unordered_map<string, int> m;
int cnt;

void run(int level, string answer) {
    if (level == 5) return;

    for (int i = 0; i < 5; i++) {
        m[answer + vowel[i]] = ++cnt;
        run(level + 1, answer + vowel[i]);
    }
}

int solution(string word) {
    int answer = 0;
    run(0, "");
    answer = m[word];
    return answer;
}

int main() {
    cout << solution("EIO");

    return 0;
}