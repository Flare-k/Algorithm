#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
// a = 97, A = 65

string convertLow(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (s[0] >= 'a' && s[0] <= 'z') {
        s[0] = toupper(s[0]);
    }
    return s;
}

string solution(string s) {
    string answer = "";

    int left = 0;
    int right = 0;
    string input;

    while (1) {
        right = s.find(' ', left);

        if (right == -1) {
            input = convertLow(s.substr(left));
            answer += input;
            break;
        }
        else {
            input = convertLow(s.substr(left, right - left));
            answer += (input + ' ');
            left = right + 1;
        }
    }


    return answer;
}

int main() {
    string s = solution("3people unFollowed me");
    cout << s;

    return 0;
}