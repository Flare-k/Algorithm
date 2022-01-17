#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();

        if (!q.empty()) {
            int card = q.front();
            q.push(card);
            q.pop();
        }
    }

    return 0;
}