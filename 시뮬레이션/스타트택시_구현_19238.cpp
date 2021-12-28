// 19238
// 벽에 가로막힌 경우, 제자리가 택시위치인경우 고려할것
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 21;
const int dx[5] = {0, -1, 1, 0, 0};
const int dy[5] = {0, 0, 0, -1, 1};
int map[MAX][MAX];  // 전체 맵의 구조
int dist[MAX][MAX]; // 각 승객이 택시를 타고 이동할 때의 거리
bool visit[MAX][MAX];
int N, M, fuel;
int tx, ty;     // 택시 위치
int current;    // 현재 승객의 번호
struct Node {
    int x, y, num, dist;    // 좌표xy, 승객번호, 최단거리 값
    bool exist;             // 승객을 완전히 이동시켰는지
};

struct Dir {
    int x, y;
};

vector<Node> start; // 각 승객의 출발 좌표
vector<Node> dest;  // 각 승객의 도착 좌표

bool cmp(Node& A, Node& B) {
    if (A.dist < B.dist) return true;
    else if (A.dist == B.dist) {
        if (A.x < B.x) return true;
        else if (A.x == B.x) return A.y < B.y;
    }
    return false;
}

// 현재 택시 위치에서 각 출발지 거리 탐색
bool findStartPoint() {
    memcpy(dist, map, sizeof(dist));
    memset(visit, false, sizeof(visit));
    
    queue<Dir> q;
    q.push({tx, ty});
    visit[tx][ty] = true;   // 택시 좌표와 승객의 좌표가 동일할 수도 있으므로 방문표시

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 1; i <= 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visit[nx][ny] || dist[nx][ny] == -1) continue;

            visit[nx][ny] = true;
            dist[nx][ny] = dist[now.x][now.y] + 1;
            q.push({nx, ny});
        }
    }

    Node result;
    int distance = 21e8;
    vector<Node> tmp;

    for (auto s : start) {
        if (s.exist == false) continue;

        int x = s.x;
        int y = s.y;

        if (distance >= dist[x][y] && visit[x][y]) {    // 택시가 출발지점과 도착지점으로 운행을 못할 수도 있음을 고려해 visit 여부 확인
            tmp.push_back({x, y, s.num, dist[x][y], s.exist});
            distance = dist[x][y];
        }
    }

    bool flag = true;

    if (!tmp.empty()) {
        sort(tmp.begin(), tmp.end(), cmp);
        result = tmp.front();
        tx = result.x;
        ty = result.y;
        start[result.num].exist = false;
        fuel -= dist[tx][ty];
        current = result.num;
    }
    else {
        flag = false;
    }

    return flag;
}

// 각 도착지 거리 탐색
bool findDestination() {
    memcpy(dist, map, sizeof(dist));
    memset(visit, false, sizeof(visit));

    int distance = 0;

    queue<Dir> q;
    q.push({tx, ty});

    Node destination = dest[current];

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 1; i <= 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visit[nx][ny] || dist[nx][ny] == -1) continue;

            visit[nx][ny] = true;
            dist[nx][ny] = dist[now.x][now.y] + 1;
            q.push({nx, ny});

            if (nx == destination.x && ny == destination.y) {
                distance = dist[nx][ny];
                dest[current].exist = false;
                tx = nx;
                ty= ny;
                break;
            }
        }
    }

    fuel -= distance;
    bool flag;

    if (fuel < 0) flag = false;
    else {
        fuel += (distance * 2);
        flag = true;
    }

    return flag;
}

bool checkPassenger() {
    for (int i = 1; i <= M; i++) {
        if (start[i].exist || dest[i].exist) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> fuel;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) map[i][j] = -1; // wall = -1
        }
    }

    // Taxi Point
    cin >> tx >> ty;

    start.resize(M + 1);
    dest.resize(M + 1);

    int sx, sy, ex, ey;

    for (int i = 1; i <= M; i++) {
        cin >> sx >> sy >> ex >> ey;
        start[i] = {sx, sy, i, 0, true};
        dest[i] = {ex, ey, i, 0, true};
    }

    while (1) {
        bool flagStart = findStartPoint();
        // 출발점을 못찾았다면
        if (flagStart == false) {
            fuel = -1;
            break;
        }

        bool flagDest = findDestination();
        // 연료를 다썼다면
        if (flagDest == false) {
            fuel = -1;
            break;
        }

        if (checkPassenger()) break;
    }

    cout << fuel;

    return 0;
}