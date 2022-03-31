#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 21
using namespace std;
// 북서동남
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int arr[MAX][MAX];
bool visit[MAX][MAX];
int N, M, K;
struct Taxi { int x, y, fuel; };
struct Dir { int x, y, dist; };
enum {
    ROAD, WALL, PASSENGER
};

Taxi taxi;
Dir vec[MAX][MAX];
bool flag;

bool cmp(Dir A, Dir B) {
    if (A.dist < B.dist) return true;
    else if (A.dist == B.dist) {
        if (A.x < B.x) return true;
        else if (A.x == B.x) return A.y < B.y;
    }
    return false;
}

void findEndPoint(int x, int y, int dist) {
    // 만약 승객을 태우러갈때 사용된 연료가 바닥이 나면 종료!
    if (taxi.fuel - dist < 0) {
        flag = true;
        return;
    }

    taxi.fuel -= dist;
    arr[x][y] = ROAD;

    int ex = vec[x][y].x;
    int ey = vec[x][y].y;

    memset(visit, false, sizeof(visit));
    queue<Dir> q;

    q.push({x, y, 0});
    visit[x][y] = true;

    Dir depart; // 도착 지점의 좌표 & 거리

    bool check = false; // 벽에 둘러싸여있는 경우 고려

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visit[nx][ny] || arr[nx][ny] == WALL) continue;

            visit[nx][ny] = true;
            q.push({nx, ny, now.dist + 1});

            if (nx == ex && ny == ey) {
                depart = {nx, ny, now.dist + 1};
                check = true;
                break;
            }
        }
    }

    // 도착지점까지 도착했다면 taxi의 상황 업데이트
    if (check && taxi.fuel - depart.dist >= 0) taxi = {depart.x, depart.y, taxi.fuel + depart.dist};
    else flag = true;

}

bool findStarttPoint() {
    // 최단 거리의 승객찾기
    queue<Dir> q;
    memset(visit, false, sizeof(visit));
    
    q.push({taxi.x, taxi.y, 0});
    visit[taxi.x][taxi.y] = true;

    vector<Dir> passenger;  // 승객의 출발 위치 벡터

    // 승객이 있는 곳과 택시가 있는 곳이 겹칠 때
    if (arr[taxi.x][taxi.y] == PASSENGER) passenger.push_back({taxi.x, taxi.y, 0});
    
    int cnt = 0;

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visit[nx][ny] || arr[nx][ny] == WALL) continue;

            visit[nx][ny] = true;
            q.push({nx, ny, now.dist + 1});

            if (arr[nx][ny] == PASSENGER) {
                passenger.push_back({nx, ny, now.dist + 1});
            }
        }
    }

    if (passenger.size() > 0) {
        sort(passenger.begin(), passenger.end(), cmp);
        Dir node = passenger.front();
        // 최단 거리의 승객을 태울 경우 도착지점 까지의 연료 변화 구하기
        findEndPoint(node.x, node.y, node.dist);
        return true;
    }

    // 태울 승객이 없다? -> 벽에 가로막혀서 못간다.

    return false;
}

void init() {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    
    int x, y;
    cin >> x >> y;
    taxi = {x, y, K};

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[x1][y1] = PASSENGER;
        vec[x1][y1] = {x2, y2};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    for (int i = 0; i < M; i++) {
        if (!findStarttPoint()) flag = true;
        if (flag) break;
    }

    if (!flag) cout << taxi.fuel << '\n';
    else cout << -1 << '\n';

    return 0;
}