#include <iostream>
#include <tuple>
using namespace std;

// 제자리, 상, 하, 좌, 우
const int dx[5] = {0, -1, 1, 0, 0};
const int dy[5] = {0, 0, 0, -1, 1};

int field[5][5] = {
    0, 0, 0, 1, 0,
    0, 0, 0, 1, 0,
    1, 1, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 0, 0
};

bool visit[5][5][5][5];

struct Node {
    int Ax, Ay;
    int Ex, Ey;
    int dist;
};

int head, tail;
int minDist = 21e8;


void BFS(int ax, int ay, int ex, int ey) {
    Node q[100] = {};

    head = 0;
    tail = 1;

    q[head] = {ax, ay, ex, ey, 0};
    visit[ax][ay][ex][ey] = true;

    while (head != tail) {
        Node now = q[head++];
        
        for (int i = 0; i < 5; i++) {
            int nAx = now.Ax + dx[i];
            int nAy = now.Ay + dy[i];
            
            if (nAx < 0 || nAy < 0 || nAx >= 5 || nAy >= 5) continue;
            if (field[nAx][nAy] == 1) continue;

            for (int j = 0; j < 5; j++) {
                int nEx = now.Ex + dx[j];
                int nEy = now.Ey + dy[j];

                if (nEx < 0 || nEy < 0 || nEx >= 5 || nEy >= 5) continue;
                if (field[nEx][nEy] == 1) continue;

                if (visit[nAx][nAy][nEx][nEy]) continue;
                
                
                visit[nAx][nAy][nEx][nEy] = true;
                q[tail++] = {nAx, nAy, nEx, nEy, now.dist + 1};

                if (nAx == nEx && nAy == nEy) {
                    cout << now.dist + 1;
                    return;
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ax, ay, ex, ey;
    cin >> ax >> ay >> ex >> ey;

    BFS(ax, ay, ex, ey);

    return 0;
}

// 0 0 4 0 = 5
// 3 1 1 4 = 4