#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, M;   // N: 도시의 크기, M: 선택될 치킨집 수
int ans;    // 전체 결과를 갱신하는 변수
int city[50][50];   // 도시의 집, 치킨집을 담는 변수
bool visit[13];     // 방문한 치킨집인지 확인
vector<pair<int, int>> house, chicken, tmp;


// 각 치킨집마다 집과의 최소거릴 계산한다.
int distance() {
    int sum = 0;

    // 집의 개수만큼 loop를 돌고
    for (int i = 0; i < house.size(); i++) {
        int x = house[i].first;
        int y = house[i].second;
        int d = 999999999;

        // M개의 치킨집과 집 사이의 최소 거리를 구한다
        for (int j = 0; j < tmp.size(); j++) {
            int nx = tmp[j].first;
            int ny = tmp[j].second;
            int dist = abs(nx - x) + abs(ny - y);

            d = min(d, dist);
        }

        sum += d;
    }
    return sum;
}

void selectChicken(int idx, int cnt) {
    if (cnt == M) {     // 만약 cnt와 M이 같다면 최소값 ans에 갱신
        ans = min(ans, distance());
        return;
    }

    for (int i = idx; i < chicken.size(); i++) {
        if (visit[i]) continue;

        visit[i] = true;
        tmp.push_back(chicken[i]);
        selectChicken(i, cnt + 1);  // Back Tracking
        visit[i] = false;
        tmp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    ans = 999999999;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                house.push_back({i, j});
            }
            if (city[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }
 
    selectChicken(0, 0);

    cout << ans;

    return 0;
}