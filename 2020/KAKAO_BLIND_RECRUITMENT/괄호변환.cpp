#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

//올바른 괄호 문자열
bool checkString(string s) {
    stack<char> temp;
    int cnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || temp.empty()) {
            temp.push(s[i]);
        } 
        else if (temp.top() == '(') {
            temp.pop();
        }
    }
    if (temp.empty()) {
        return true;
    }
    
    return false;
}
// 균형잡힌 괄호 문자열

string strParsing(string s, int start, int end) {
    string res = "";
   
    for (int i = start; i <= end; i++) {
        res += s[i];
    }

    return res;
}

string solution(string w) {
    if (w.length() == 0 || checkString(w)) return w;

    string u = "", v = "", tmp = "", answer;
    int cntU = 0, cntV = 0;

    for (int i = 0; i < w.length(); i++) {
        if (w[i] == '(') {
            cntU++;
        } 
        else if (w[i] == ')') {
            cntV++;
        }

        tmp += w[i];

        if (cntU == cntV) {
            // u = strParsing(w, 0, i);
            u = tmp;
            // v = strParsing(w, i + 1, w.length() - 1);
            for (int j = i + 1; j < w.length(); j++) {
                v += w[j];
            }
            break;
        }
    }

    if (checkString(u)) {
        answer += u;
        answer += solution(v);
        return answer;
    } 
    else {
        string setting = "(";
        setting += solution(v);
        setting += ")";

        string tmp2;
        for (int i = 1; i < u.length() - 1; i++) {
            tmp2 += u[i];
        }
        u = tmp2;

        // u = strParsing(u, 1, u.length() - 2);
        for (int i = 0; i < u.length(); i++) {
            if (u[i] == '(') {
                setting += ")";
            } 
            else {
                setting += "(";
            }
        }
        answer += setting;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string req;
    cin >> req;

    cout << solution(req) << '\n';
    
    return 0;
}
/*
Test Case
)()()()(  ->  (((())))
(()())()  ->  (()())()
)(        ->  ()
()))((()  ->  ()(())()
)()(()    ->  ((()))
())()(    ->  ()(())
*/