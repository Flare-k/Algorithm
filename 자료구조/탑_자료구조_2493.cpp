#include <iostream>
#include <stack>
using namespace std;

int N, height;

struct Node {
    int idx, height;
};

stack<Node> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> height;

        while (!st.empty()) {
            if (height < st.top().height) {
                cout << st.top().idx << ' ';
                break;
            }
            st.pop();
        }

        if (st.empty()) {
            cout << 0 << ' ';
        }

        st.push({i + 1, height});
    }
    

    return 0;
}