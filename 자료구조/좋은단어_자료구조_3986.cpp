#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
한 글자씩 매핑하는것이다
즉, AAA이면 1,2번 A가 아치형을 그리고 2,3번 A가 아치형을 그리는데 교점이 발생하게 된다.
그렇기 때문에 현재 단어와 스택의 top이 같다면 무조건 아치를 그린다고 가정해주면 된다. (ABBA 처럼 A가 큰 아치를 띄는 경우는 교점이 없으니까)
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, cnt = 0;

    cin >> n;

    while (n--) {
        stack<char> st;
        
        string str;
        cin >> str;

        for (char ch : str) {
            if (st.empty() || st.top() != ch) st.push(ch);
            else if (st.top() == ch) st.pop();
        }

        if (st.empty()) cnt++;
   }

   cout << cnt;

    return 0;
}