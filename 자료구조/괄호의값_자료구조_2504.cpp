#include <iostream>
#include <string>
#include <stack>
using namespace std;

string ch;
long long answer;

void run() {
    stack<char> st;
    int len = ch.length();
    int num = 1;
    bool impossible = false;

    for (int i = 0; i < len; i++) {
        if (ch[i] == '(') {
            num *= 2;
            st.push(ch[i]);
        }
        else if (ch[i] == '[') {
            num *= 3;
            st.push(ch[i]);
        }
        else if (ch[i] == ')') {
            if ((st.empty() || st.top() != '(')) {
                impossible = true;
                break;
            }

            if (ch[i - 1] == '(') answer += num;
            num /= 2;
            st.pop();
        }
        else if (ch[i] == ']') {
            if (st.empty() || st.top() != '[') {
                impossible = true;
                break;
            }

            if (ch[i - 1] == '[') answer += num;
            num /= 3;
            st.pop();
        }
    }

    if (impossible || !st.empty()) cout << 0 << '\n';
    else cout << answer << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ch;
    run();
    
    return 0;
}