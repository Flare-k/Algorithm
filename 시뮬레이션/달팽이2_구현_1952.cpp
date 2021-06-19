#include <iostream>
using namespace std;

const int MAX = 101;
int r, c;
int arr[MAX][MAX];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    int totalCnt = r * c - 1;
    int cnt = 0;

    arr[0][0] = 1;
    int x = 0, y = 0;

    int idx = 0;
    while (totalCnt > 0) {

        int nx = x + dx[idx % 4];
        int ny = y + dy[idx % 4];

        if ((nx < 0 || ny < 0 || nx >= r || ny >= c) || (arr[nx][ny] == 1)) {
            cnt++;  // 꺾기
            idx++;
            continue;
        }
        
        arr[nx][ny] = 1;
        totalCnt--;
        
        x = nx;
        y = ny;
    }

    cout << cnt;

    return 0;
}