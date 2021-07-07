#include <iostream>
#include <stack>
#include<string>
using namespace std;

int solution(string s) {

    stack<char> st;

    while (!s.empty()) {
        st.push(s.back());
        s.pop_back();

        while (!st.empty() && s.back() == st.top()) {
            st.pop();
            s.pop_back();
        }
    }

    int answer = 0;
    if (st.empty()) answer = 1;

    return answer;
}

int main() {
    int ans = solution("ccc");

    cout << ans;

    return 0;
}