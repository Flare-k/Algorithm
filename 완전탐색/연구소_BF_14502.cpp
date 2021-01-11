#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
/*
그냥 1을 3개씩 배치해서 무작정 다 구해볼까...
*/

int n, m;
const int MAX = 10;
int arr[MAX][MAX];
int subArr[MAX][MAX];

vector<pair<int, int> > vec;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int answer = 0;

int BFS() {
    queue<pair<int, int> > que;
    
    for (int i = 0; i < vec.size(); i++) {
        que.push(make_pair(vec[i].first, vec[i].second));
    }

    while (!que.empty()) {
        int x = que.front().first;   // 현재 2인 곳의 x좌표
        int y = que.front().second;  // 현재 2인 곳의 y좌표
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (subArr[nx][ny] == 0) {  // 벽 3개를 다 배치하고나서
                subArr[nx][ny] = 2;  // 현재 2인 x,y에서 상하좌우에 0이 존재한다면
                                    // 2로 전염시킨다.
                que.push(make_pair(nx, ny));
            }
        }

    }

    int size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (subArr[i][j] == 0) {
                size++;
            }
        }
    }  // 전염시킬 곳은 다 전염시키고 나서 0인 곳에 대해서 카운팅을 한다.
    answer = max(size, answer);  // 지금까지 나온 answer 중에서 최대값을 가린다.
    
    return answer;
}

int wall(int cnt) {
    if (cnt == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                subArr[i][j] = arr[i][j];
            }  // cnt == 3 즉, 벽을 세개 모두 세운 결과에 대해 subArr에 복사해서
                // BFS 함수로 넘어간다.
        }
        return BFS();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;    //만약 0이라면 벽을 세운다.
                wall(cnt + 1);    // 벽이 3개 세워질 동안 재귀
                arr[i][j] = 0;  // 재귀 끝나면 다시 원상복구
            }
        }
    }

    return 1;
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 2) {
                vec.push_back(make_pair(i, j));
            }

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                wall(1);
                arr[i][j] = 0;
            }
        }
    }
    
    cout << answer << endl;

    return 0;
}