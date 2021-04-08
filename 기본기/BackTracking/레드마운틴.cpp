#include <iostream>
using namespace std;

int n;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int mountain[15][15];
bool visit[15][15];

void climb(int x, int y) {
    visit[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (mountain[nx][ny]) continue;

        if (!visit[nx][ny]) {
            climb(nx, ny);
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mountain[i][j];
        }
    }

    climb(0, 0);

    if (visit[n - 1][n - 1]) {
        cout << "가능" << '\n';
    }
    else {
        cout << "불가능" << '\n';
    }

    return 0;
}