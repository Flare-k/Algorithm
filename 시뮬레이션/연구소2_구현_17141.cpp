#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 51
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int lab[MAX][MAX];  // 연구소
int cpy[MAX][MAX];  // 초기 연구소 상태 복사
int dist[MAX][MAX];  // 바이러스가 퍼지는 속도
bool visit[MAX][MAX];
enum { EMPTY, WALL, VIRUS };
struct Node { int x, y; };

vector<Node> virus; // 바이러스를 놓을 수 있는 위치
vector<int> vec;    // next_permutation을 돌리기위한 벡터
queue<Node> q;

int answer = 21e8;
int limit, nonelimit;   // limit: next_permutation을 돌리는 횟수, nonelimit: -1이 나오는 횟수
int N, M;

bool check() {
    int maxx = -21e8;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lab[i][j] == EMPTY && dist[i][j] == 0) return false;
            maxx = max(maxx, dist[i][j]);
        }
    }

    answer = min(answer, maxx);

    return true;
}

void run() {
    memset(dist, 0, sizeof(dist));

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visit[nx][ny] || lab[nx][ny] == WALL) continue;

            visit[nx][ny] = true;
            dist[nx][ny] = dist[now.x][now.y] + 1;
            q.push({nx, ny});
        }
    }

    // 만약 다 안퍼졌다면 nonelimit 증가
    if (!check()) nonelimit++;
}

void init () {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == VIRUS) virus.push_back({i, j});
        }
    }

    memcpy(cpy, lab, sizeof(cpy));  // 초기 바이러스 상태 복사
    vec.resize(virus.size());

    for (int i = 0; i < M; i++) {
        vec[i] = 1;
    }

    sort(vec.begin(), vec.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    do {
        memcpy(lab, cpy, sizeof(lab));
        memset(visit, false, sizeof(visit));
        
        limit++;

        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == 0) {
                lab[virus[i].x][virus[i].y] = 0;
            }
            else {
                q.push({virus[i].x, virus[i].y});
                visit[virus[i].x][virus[i].y] = true;
            }
        }

        run();

    } while (next_permutation(vec.begin(), vec.end()));

    if (limit == nonelimit) answer = -1;
    
    cout << answer << '\n';

    return 0;
}