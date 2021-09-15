#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 65;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int arr[MAX][MAX];
int temp[MAX][MAX];
bool visit[MAX][MAX];

int N, Q;

struct Node {
    int x, y;
};

void meltingIce() {
    int cnt;
    vector<Node> list;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            
            cnt = 0;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (arr[nx][ny] > 0) cnt++;
            }

            if (cnt < 3 && arr[x][y] > 0) list.push_back({x, y});
        }
    }

    for (auto v : list) {
        arr[v.x][v.y]--;
    }

}

int maxSize(int x, int y) {
    queue<Node> q;
    q.push({x, y});
    visit[x][y] = true;
    int cnt = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visit[nx][ny] == true || arr[nx][ny] == 0) continue;

            q.push({nx, ny});
            visit[nx][ny] = true;
            cnt++;
        }
    }

    return cnt;
}

// size 만큼 시계방향 회전
void rotateIce(int size) {
    memcpy(temp, arr, sizeof(arr));

    int ridx = 0;
    int cidx = 0;
    int r = 0, c = 0;
    int rowIter = N / size;
    int colIter = N / size;

    while (rowIter--) {
        for (int k = 0; k < colIter; k++){
            for (int i = r; i < r + size; i++) {
                ridx = r + size - 1;
                for (int j = c; j < c + size; j++) {
                    arr[i][j] = temp[ridx--][cidx];
                }
                cidx++;
            }
            c += size;
        }

        cidx = 0;
        r += size;
        c = 0;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> Q;

    N = pow(2, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // 길이를 Q만큼 반복
    int L;
    for (int i = 0; i < Q; i++) {
        cin >> L;
        
        if (L > 0) rotateIce(pow(2, L));

        meltingIce();
    }

    int totalSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            totalSum += arr[i][j];
        }
    }

    int maxSizeSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] != 0 && !visit[i][j]) {
                int maxx = maxSize(i, j);
                maxSizeSum = max(maxSizeSum, maxx);
            }
        }
    }
    
    cout << totalSum << '\n' << maxSizeSum;
    
    return 0;
}