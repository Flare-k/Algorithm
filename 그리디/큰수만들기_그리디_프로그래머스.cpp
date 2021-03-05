#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int len = number.length() - k;
    int start = 0;

    for (int i = 0; i < len; i++) {
        char maxNum = number[start];
        int maxIdx = start;
        for (int j = start; j <= k + i; j++) {
            if (maxNum < number[j]) {
                maxNum = number[j];
                maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += maxNum;
    }

    return answer;
}

int main() {
    cout << solution("1924", 2) << '\n';
    cout << solution("1231234", 3) << '\n';
    cout << solution("4177252841", 4) << '\n';
    return 0;
}