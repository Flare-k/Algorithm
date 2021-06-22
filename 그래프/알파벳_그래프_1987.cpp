#include <iostream>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX = 30;

int r, c;
char arr[MAX][MAX];
bool alpha[MAX];
int maxx = 1;

void run(int x, int y, int cnt) {

    alpha[arr[x][y] - 'A'] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (alpha[arr[nx][ny] - 'A'] == true) continue;
        
        run(nx, ny, cnt + 1);
        alpha[arr[nx][ny] - 'A'] = false;
        maxx = max(maxx, cnt + 1);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    run(0, 0, 1);

    cout << maxx;

    return 0;
}
