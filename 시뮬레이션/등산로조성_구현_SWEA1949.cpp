#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#define MAX 10
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int T, N, K;
int arr[MAX][MAX];
int tmp[MAX][MAX];
struct Node {
    int x, y, dist;
};
vector<Node> bong;
int path;

// 봉우리별로 등산로 길이 비교
// 0,0 ~ N,N까지 각각 0~K까지 파면서..
void run() {
    // 각 봉우리별 등산로의 길이
    for (int i = 0; i < bong.size(); i++) {
        queue<Node> q;

        q.push({bong[i].x, bong[i].y, 1});

        while (!q.empty()) {
            Node now = q.front();
            q.pop();
            
            path = max(path, now.dist);

            for (int j = 0; j < 4; j++) {
                int nx = now.x + dx[j];
                int ny = now.y + dy[j];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (tmp[now.x][now.y] <= tmp[nx][ny]) continue;

                q.push({nx, ny, now.dist + 1});
            }
        }
        
    }

}

void setBong(int maxx) {
    bong.clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == maxx) bong.push_back({i, j});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    int idx = 1;
    while (T--) {
        path = -21e8;
        memset(arr, 0, sizeof(arr));

        cin >> N >> K;

        int maxx = -21e8;
        
        // 산 능선 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                maxx = max(maxx, arr[i][j]);
            }
        }

        // 봉우리 초기화
        setBong(maxx);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int dig = 0; dig <= K; dig++) {
                    if (i == 2 && j == 3 && dig == 1) {
                        int a= 1;
                    }
                    memcpy(tmp, arr, sizeof(tmp));
                    tmp[i][j] -= dig;
                    run();
                }
            }
        }

        cout << '#' << idx++ << ' ' << path << '\n';
    }

	return 0;
}

/*
10
5 1
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
3 2
1 2 1
2 1 2
1 2 1
5 2
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
4 4
8 3 9 5
4 6 8 5
8 1 5 1
4 9 5 5
4 1
6 6 1 7
3 6 6 1
2 4 2 4
7 1 3 4
5 5
18 18 1 8 18
17 7 2 7 2
17 8 7 4 3
17 9 6 5 16
18 10 17 13 18
6 4
12 3 12 10 2 2
13 7 13 3 11 6
2 2 6 5 13 9
1 12 5 4 10 5
11 10 12 8 2 6
13 13 7 4 11 7
7 3
16 10 14 14 15 14 14
15 7 12 2 6 4 9
10 4 11 4 6 1 1
16 4 1 1 13 9 14
3 12 16 14 8 13 9
3 4 17 15 12 15 1
6 6 13 6 6 17 12
8 5
2 3 4 5 4 3 2 1
3 4 5 6 5 4 3 2
4 5 6 7 6 5 4 3
5 6 7 8 7 6 5 4
6 7 8 9 8 7 6 5
5 6 7 8 7 6 5 4
4 5 6 7 6 5 4 3
3 4 5 6 5 4 3 2
8 2
5 20 15 11 1 17 10 14
1 1 11 16 1 14 7 5
17 2 3 4 5 13 19 20
6 18 5 16 6 7 8 5
10 4 5 4 9 2 10 16
2 7 16 5 8 9 10 11
12 19 18 8 7 11 15 12
1 20 18 17 16 15 14 13
#1 6
#2 3
#3 7
#4 4
#5 2
#6 12
#7 6
#8 7
#9 10
#10 19
*/
