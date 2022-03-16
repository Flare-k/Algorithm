#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    while (N--) {
        stack<char> st1;
        stack<char> st2;
        string testcase;
        
        cin >> testcase;
        
        for (char ch : testcase) {
            if (ch == '<' && !st1.empty()) {
                char c = st1.top();
                st1.pop();
                st2.push(c);
            }
            else if (ch == '>' && !st2.empty()) {
                char c = st2.top();
                st2.pop();
                st1.push(c);
            }
            else if (ch == '-' && !st1.empty()) {
                st1.pop();
            }
            else if (ch != '<' && ch != '>' && ch != '-') {
                st1.push(ch);
            }
        }

        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        string answer = "";

        while (!st1.empty()) {
            answer += st1.top();
            st1.pop();
        }

        reverse(answer.begin(), answer.end());
        
        cout << answer << '\n';
    }

    return 0;
}