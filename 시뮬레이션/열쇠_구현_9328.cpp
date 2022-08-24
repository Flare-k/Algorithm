#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#define MAX 102
using namespace std;

int T;
char arr[MAX][MAX];
bool visit[MAX][MAX];
map<char, bool> m;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int h, w, cnt;
struct Node {
    int x, y;
};

void checkDoor(int x, int y, char k) {
    arr[x][y] = '.';

    if (!m.count(k)) {
        m[k] = true;

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (arr[i][j] == toupper(k)) arr[i][j] = '.';
            }
        }
    }
}

void findDocument(int x, int y) {
    memset(visit, false, sizeof(visit));
    queue<Node> q;
    q.push({x, y});

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if (x < 0 || x > h + 1 || y < 0 || y > w + 1) continue;
        if (visit[x][y] || arr[x][y] == '*') continue;
        if (arr[x][y] >= 'A' && arr[x][y] <= 'Z') continue;

        visit[x][y] = true;

        if (arr[x][y] == '$') {
            cnt++;
            arr[x][y] = '.';
        }
        
        if (arr[x][y] >= 'a' && arr[x][y] <= 'z') {
            char k = arr[x][y];
            arr[x][y] = '.';

            if (!m.count(k)) {
                m[k] = true;

                for (int i = 1; i <= h; i++) {
                    for (int j = 1; j <= w; j++) {
                        if (arr[i][j] == toupper(k)) arr[i][j] = '.';
                    }
                }

                // 문을 열면 경로 다시 시작
                memset(visit, false, sizeof(visit));
                while(!q.empty()) q.pop();
                q.push({x, y});
                continue;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            q.push({nx, ny});
        }
    }
}

int main() {
    cin >> T;

    while (T--) {
        memset(arr, 0, sizeof(arr));
        m.clear();
        string key;
        
        cin >> h >> w;
        
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                if (i == 0 || i == h + 1 || j == 0 || j == w + 1) arr[i][j] = '.';
            }
        }

        cin >> key;

        for (char k : key) {
            m[k] = true;

            for (int i = 1; i <= h; i++) {
                for (int j = 1; j <= w; j++) {
                    if (arr[i][j] == toupper(k)) arr[i][j] = '.';
                }
            }
        }

        cnt = 0;
        findDocument(0, 0);
        cout << cnt << '\n';
    }

    return 0;
}