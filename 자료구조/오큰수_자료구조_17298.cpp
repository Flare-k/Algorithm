#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> st;
int arr[1000001];
int answer[1000001];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.empty()) answer[i] = -1;
        else answer[i] = st.top();

        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}