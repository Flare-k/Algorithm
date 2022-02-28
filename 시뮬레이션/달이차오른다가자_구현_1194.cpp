#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 51
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
char arr[MAX][MAX];
bool visit[64][MAX][MAX];
int N, M, mx, my;
struct Node {
    int x, y, dist, key;
};

int run() {
    queue<Node> q;
    q.push({mx, my, 0, 0});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        int x = now.x;
        int y = now.y;
        int dist = now.dist;
        int key = now.key;

        if (arr[x][y] == '1') return dist;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (arr[nx][ny] == '#') continue;
            

            // 열쇠
            if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f') {
                int nkey = key | (1 << (arr[nx][ny] - 'a'));    // 기존 열쇠 현황과 새로운 열쇠 추가

                if (visit[nkey][nx][ny]) continue;

                q.push({nx, ny, now.dist +1, nkey});
                visit[nkey][nx][ny] = true;
            }
            // 문
            else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F') {
                int check = key & (1 << (arr[nx][ny] - 'A'));   // 기존 열쇠에서 문에 해당하는 곳과 일치한다면?

                if (check == 0 || visit[key][nx][ny]) continue;

                q.push({nx, ny, now.dist + 1, key});
                visit[key][nx][ny] = true;
            }
            // 비어있는 경우
            else if (!visit[key][nx][ny]) {
                q.push({nx, ny, now.dist + 1, key});
                visit[key][nx][ny] = true;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '0') {
                mx = i;
                my = j;
            }
        }
    }

    cout << run() << '\n';

    return 0;
}