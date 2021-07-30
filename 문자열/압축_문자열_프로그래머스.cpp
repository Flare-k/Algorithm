#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

int idx = 1;

// A~Z 초기화
void init() {
    for (char a = 'A'; a <= 'Z'; a++) {
        string s(1, a);
        m[s] = idx++;
    }
}

vector<int> solution(string msg) {
    init();

    vector<int> answer;
    int len = msg.length();

    int s = 0, e = 1;
    int elem;
    bool flag = false;

    while (!flag) {
        string tmp(1, msg[s]);  // 시작 알파벳

        while (m.count(tmp)) {  // 만약 압축된 알파벳이면 몇번째인지 elem에 갱신하고 다음 알파벳을 뒤에 붙여 확인한다.
            elem = m[tmp];

            // 종료조건
            if (e - 1 == len - 1) {
                flag  = true;
                break;
            }

            tmp += msg[e++];
        }

        if (flag) break;

        answer.push_back(elem);
        m[tmp] = idx++;

        s = e - 1;
    }

    answer.push_back(elem); // 맨 마지막 값


    return answer;
}

int main() {

    vector<int> ans = solution("ABABABABABABABAB");

    for (int num : ans) {
        cout << num << ' ';
    }

    return 0;
}