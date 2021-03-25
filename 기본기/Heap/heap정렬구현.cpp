#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> pq;

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        pq.push(s[i]);
    }

    for (int i = 0; i < s.length(); i++) {
        cout << (char)pq.top();
        pq.pop();
    }

    return 0;
}