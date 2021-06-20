#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string oper;
    cin >> oper;


    int first = 0;
    int idx = 0;

    while (1) {
        if (oper[idx] == '*' || oper[idx] == '/') {
            string firstSec = oper.substr(0, idx - 1);
            string midSec = oper.substr(idx - 1, 3);
            string endSec = oper.substr(idx + 2);
            oper = firstSec + '(' + midSec + ')' + endSec;

            first = idx + 4;
            idx += 2;
        }

        idx++;
        if (idx > oper.length()) break;
    }

    stack<char> brac;
    stack<char> operList;

    for (char ch : oper) {
        if (ch == '(') brac.push('(');
        else if (ch == ')' && brac.top() == '(') {
            brac.pop();
            if (!operList.empty()) {
                cout << operList.top();
                operList.pop();
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            operList.push(ch);
        }
        else {
            cout << ch;
        }
    }
    while (!operList.empty()) {
        cout << operList.top();
        operList.pop();
    }

    return 0;
}