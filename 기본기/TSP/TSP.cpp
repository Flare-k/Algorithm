#include <iostream>
#define MAX 21e8
#define CITY 16
using namespace std;
/* 
외판원순회는 특정 도시에서 도시로 이동할 때 드는 비용이 주어졌을 때, 
불특정한 도시에서 출발해 모든 도시를 돌고 다시 출발 도시로 돌아왔을 때 드는 최소 비용을 구하는 문제이다.
출발도시를 따로 정해주지 않아도 모든 도시를 돌아서 다시 출발도시로 돌아오는데 드는 최소비용은 같다.
즉, 사이클이 발생하게 된다.
*/

/* 
외판원 순회는 NP문제로 DP와 비트마스크를 이용해 구한다.
- DP는 특정 도시들을 방문한 상태일 때 최소비용을 저장해놓고 사용한다. (Memoization)
- 비트마스크는 특정 도시를 방문한 상태를 저장할 때 사용한다.
*/

// 이미 방문한 도시들의 집합이 i이고, 현재 있는 도시가 j일때, 
// 방문하지 않은 나머지 도시들을 모두 방문한 뒤 출발 도시로 돌아올 때 드는 최소비용

int N;
int d[1 << CITY][CITY] = {0};
int arr[CITY][CITY];

// visit: 이미 방문한 도시체크
// now: 이번에 지날 도시 번호
int TSP(int visit, int now) {

    // now번 도시 방문 추가
    visit |= (1 << now);

    // 모든 도시를 지난 경우
    if (visit == (1 << N) - 1) {
        // now -> 0(출발 도시)로 가는 경로가 있어야 돌아갈 수 있다.
        if (arr[now][0] > 0) return arr[now][0];    // 여행 비용 반환
        return MAX; // 불가능한 경우 MAX 반환
    }

    int& ret = d[visit][now];

    // memoization
    if (ret > 0) return ret;

    ret = MAX;

    for (int i = 0; i < N; i++) {
        // now -> 아직 방문하지 않은 i번 도시로 가는 경로가 있는 경우
        if (i != now && (visit & (1 << i)) == 0 && arr[now][i] > 0) {
            // 최소 비용 갱신
            int tmp = TSP(visit, i) + arr[now][i];
            if (ret > tmp) ret = tmp;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int answer = TSP(0, 0);

    if (answer == MAX) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}