#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int MAX = 1000001;
    bool visit[MAX]{false, };
    int F, S, G, U, D; // 총 층수, 현재 층수, 도착 층수, Up, Down
    cin >> F >> S >> G >> U >> D; // 10 1 10 2 1

    visit[S] = true;
    queue<pair<int, int>> elevator;
    elevator.push({S, 0});

    int ans = -1;
    while (!elevator.empty()) {
        int stair = elevator.front().first;
        int cnt = elevator.front().second;
        elevator.pop();

        if (stair == G){
            ans = cnt;
            break;
        }
        // Up과 Down의 경우의 수를 순서대로 모두 고려한다.
        if (stair + U <= F && !visit[stair + U]) {
            visit[stair + U] = true;
            elevator.push({stair + U, cnt + 1});
        }

        if (stair - D > 0 && !visit[stair - D]) {
            visit[stair - D] = true;
            elevator.push({stair - D, cnt + 1});
        }

    }

    if (ans != -1) {
        cout << ans << '\n';
    }
    else {
        cout << "use the stairs" << '\n';
    }
  
    return 0;
}