#include <iostream>
#include <vector>
using namespace std;

// 우 상 좌 하
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
const int MAX = 101;

vector<int> dragon_dir;
int map[MAX][MAX];
int n, x, y, dir, gen;

void drawDragonCurve() {
    int size = dragon_dir.size();

    for (int i = size - 1; i >= 0; i--) {
        int nDir = (dragon_dir[i] + 1) % 4;

        y += dy[nDir];
        x += dx[nDir];
        map[y][x] = 1;
        dragon_dir.push_back(nDir);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while (n--) {
        cin >> x >> y >> dir >> gen;
        dragon_dir.clear();

        map[y][x] = 1;
        x += dx[dir];
        y += dy[dir];
        map[y][x] = 1;

        dragon_dir.push_back(dir);

        while (gen--) {
            drawDragonCurve();
        }
    }

    int cnt = 0;

    // 모든 꼭짓점
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
                cnt++;
        }
    }

    cout << cnt;


    return 0;
}