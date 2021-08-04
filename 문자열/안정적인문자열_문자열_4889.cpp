#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int idx = 1;
    while (1) {
        stack<char> st;

        string testcase;
        cin >> testcase;

        if (testcase.front() == '-') break;

        for (char ch : testcase) {
            if (st.empty() || ch == '{') {
                st.push(ch);
            }
            else if (st.top() == '}') {
                st.push(ch);
            }
            else if (st.top() == '{') {
                st.pop();
            }
        }

        int cnt = 0;

        if (st.size() % 2 == 1) st.pop();

        while (!st.empty()) {
            char pre = st.top();
            st.pop();
            char post = st.top();
            st.pop();

            if (pre == post) cnt++;
            else cnt += 2;
        }

        cout << idx++ << ". " << cnt << '\n';
    }
    return 0;
}