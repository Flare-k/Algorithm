#include <iostream>
#include <utility>
#include <tuple>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, v;
    cin >> n;

    priority_queue<tuple<int, char, char>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v;
            if (v == 0) continue;
            pq.push(make_tuple(v, 'A' + i, 'A' + j));
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << get<1>(pq.top()) << "-" << get<2>(pq.top()) << " " << get<0>(pq.top()) << '\n';
        pq.pop();
    }

    return 0;
}