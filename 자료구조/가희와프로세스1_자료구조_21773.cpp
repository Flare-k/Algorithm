#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int T, N;
using edge = tuple<int, int, int>;
priority_queue<edge> pq;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T >> N;

    for (int i = 0; i < N; i++) {
        int id, time, value;
        cin >> id >> time >> value;
        pq.push({value, -id, time});
    }

    for (int i = 0; i < T; i++) {
        edge now = pq.top();
        pq.pop();

        cout << -get<1>(now) << '\n';

        if (get<2>(now) - 1 > 0) {
            pq.push({get<0>(now) - 1, get<1>(now), get<2>(now) - 1});
        }
    }

    return 0;
}