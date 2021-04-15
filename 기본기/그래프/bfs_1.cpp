#include <iostream>
#include <cstring>
using namespace std;

// queue STL 안 쓰고 BFS

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x;
    int y;
};

int head;
int tail;   // 배열의 맨끝

Node q[30];
int map[4][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(map, 0, sizeof(map));

    q[0] = {3, 1};
    map[3][1] = 1;
    
    head = 0;
    tail = 1; 
    
    while (head != tail) {
        Node now = q[head];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
            if (map[nx][ny] != 0) continue;

            map[nx][ny] = map[now.x][now.y] + 1;
            q[tail++] = {nx, ny};
        }

        head++;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}