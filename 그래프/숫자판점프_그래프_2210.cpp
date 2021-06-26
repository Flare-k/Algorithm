#include <iostream>
#include <set>
using namespace std;

int arr[5][5];
set<int> ans;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void run(int x, int y, int num, int cnt) {
    if (cnt == 6) {
        ans.insert(num);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        run(nx, ny, num * 10 + arr[nx][ny], cnt + 1);
    }

}

int main() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            run(i, j, arr[i][j], 1);
        }
    }

    cout << ans.size();

    return 0;
}