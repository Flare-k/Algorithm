#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

bool correct(deque<char> s) {
    stack<char> gh;
    
    for (int i = 0; i < s.size(); i++) {
        if (gh.empty() || (s[i] != ']' && s[i] != '}' && s[i] != ')')) {
            gh.push(s[i]);
        }
        else {
            if (gh.top() == '[' && s[i] == ']') gh.pop();
            else if (gh.top() == '{' && s[i] == '}') gh.pop();
            else if (gh.top() == '(' && s[i] == ')') gh.pop();
        }
    }

    return gh.empty() ? true : false;
}

int solution(string s) {
    int answer = 0;
    deque<char> newStr;

    for (char c : s) {
        newStr.push_back(c);
    }

    for (int i = 0; i < s.length(); i++) {
        if (correct(newStr)) answer++;
        
        char tmp = newStr[0];
        newStr.pop_front();
        newStr.push_back(tmp);
    }
    
    return answer;
}

int main() {

    cout << solution("[)(]");

    return 0;
}