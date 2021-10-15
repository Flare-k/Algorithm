#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convertToNum(string s) {
    if (s == "zero") return "0";
    else if (s == "one") return "1";
    else if (s == "two") return "2";
    else if (s == "three") return "3";
    else if (s == "four") return "4";
    else if (s == "five") return "5";
    else if (s == "six") return "6";
    else if (s == "seven") return "7";
    else if (s == "eight") return "8";
    else if (s == "nine") return "9";
    return "-1";
}

int solution(string s) {
    string answer = "";

    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') answer += s[i];
        else {
            tmp += s[i];

            if (tmp.length() >= 3) {
                string a = convertToNum(tmp);
                if (a != "-1") {
                    answer += a;
                    tmp = "";
                }
            }
        }
    }

    return stoi(answer);
}

int main() {

    cout << solution("one4seveneight") << '\n';
    cout << solution("23four5six7") << '\n';
    cout << solution("2three45sixseven") << '\n';
    cout << solution("123") << '\n';

    return 0;
}