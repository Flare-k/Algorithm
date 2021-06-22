#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1001;
int r, c;
int chess[MAX][MAX];
bool visit[MAX][MAX];

const int qdx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int qdy[] = {0, 0, -1, 1, -1, 1, -1, 1};

const int kdx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int kdy[] = {1, 2, 2, 1, -1, -2, -2, -1};

struct Node {
    int x, y;
    int horse;
};

void queenRoute(int x, int y) {

    for (int i = 0; i < 8; i++) {
        int nx = x + qdx[i];
        int ny = y + qdy[i];

        while (1){
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) break;
            if (chess[nx][ny] != 0) break;

            visit[nx][ny] = true;

            nx += qdx[i];
            ny += qdy[i];
        }
    }
}

void knightRoute(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + kdx[i];
        int ny = y + kdy[i];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (chess[nx][ny] != 0) continue;
        visit[nx][ny] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    int cnt, x, y;
    int horse = 1;  // Q = 1, K = 2, P = 3
    vector<Node> pos;

    for (int i = 0; i < 3; i++) {
        cin >> cnt;
        
        while (cnt--) {
            cin >> x >> y;
            chess[x - 1][y - 1] = horse;
            pos.push_back({x - 1, y - 1, horse});
        }

        horse++;
    }

    for (int i = 0; i < pos.size(); i++) {
        if (pos[i].horse == 1) {
            queenRoute(pos[i].x, pos[i].y);
        }
        else if(pos[i].horse == 2) {
            knightRoute(pos[i].x, pos[i].y);
        }
    }

    int safeArea = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (chess[i][j] == 0 && !visit[i][j]) safeArea++;
        }
    }

    cout << safeArea;

    return 0;
}