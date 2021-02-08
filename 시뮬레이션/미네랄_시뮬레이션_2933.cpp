#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#define MAX 101

using namespace std;

int r, c, num;  // 행열 & 막대기 개수
char arr[MAX][MAX];
bool visit[MAX][MAX];

vector<pair<int, int>> cluster;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};


void clusterDown() {
    bool visitCluter[MAX][MAX];
    memset(visitCluter, false, sizeof(visitCluter));

    // cluster인 곳 . 표시하고 미방문 표시로 갱신
    for (int i = 0; i < cluster.size(); i++) {
        int x = cluster[i].first;
        int y = cluster[i].second;

        if (r - 1 == x) 
            return;
        else {
            arr[x][y] = '.';
            visit[x][y] = false;
        }
    }

    // 클러스터인 좌표 중 한 행씩 아래로 밀어서 x 표시하고 방문 체크
    for (int i = 0; i < cluster.size(); i++) {
        int x = cluster[i].first;
        int y = cluster[i].second;

        arr[x + 1][y] = 'x';
        visit[x + 1][y] = true;
        visitCluter[x + 1][y] = true;
        cluster[i].first += 1;  // 한 행씩 밀었으므로 cluster vector에도 표시
    }

    for (int i = 0; i < cluster.size(); i++) {
        int x = cluster[i].first;
        int y = cluster[i].second;

        if (x == r - 1)
            return;
        if (arr[x + 1][y] == 'x' && !visitCluter[x + 1][y]) // 다른 클러스터의 미네랄일 경우
            return;
    }

    clusterDown();
    return;
}


void DFS(int x, int y) {
    cluster.push_back({x, y});

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx > r || ny < 0 || ny > c) continue;
        if (arr[nx][ny] == 'x' && !visit[nx][ny]) {
            visit[nx][ny] = true;
            DFS(nx, ny);
        }
    }

}

void clust() {
    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            if(arr[i][j] == 'x' && !visit[i][j]) {  // 아직 방문하지 않은 미네랄이라면
                cluster.clear();
                visit[i][j] = true;
                DFS(i, j);  // 클러스터 형성
                clusterDown();  // 클러스터 다운시키기
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    // 초기값 세팅
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> num;
    // 창영, 상근의 막대기 높이별 미네랄 변화
    for (int i = 0; i < num; i++) {
        memset(visit, false, sizeof(visit));

        int h;  // 막대기 높이
        cin >> h;

        // 창영 (왼쪽 -> 오른쪽)
        if (i % 2 == 0) {
            for (int i = 0; i < c; i++) {
                if (arr[r - h][i] == 'x'){
                    arr[r - h][i] = '.';
                    break;
                }
            }
        }
        // 상근 (오른쪽 -> 왼쪽)
        else {
            for (int i = c - 1; i >= 0; i--) {
                if (arr[r - h][i] == 'x') {
                    arr[r - h][i] = '.';
                    break;
                }
            }
        }

        clust();
    }


    // 출력
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}