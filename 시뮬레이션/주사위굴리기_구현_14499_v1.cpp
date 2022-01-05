#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dice[6] {0, 0, 0, 0, 0, 0}; // 위, 뒤, 오른쪽, 왼쪽, 앞, 바닥

    const int dx[5]{0, 0, 0, -1, 1};
    const int dy[5]{0, 1, -1, 0, 0};    //제자리, 동 서 남 북

    int r, c, x, y, move;
    cin >> r >> c >> x >> y >> move;

    int map[20][20];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < move; i++) {
        int n;
        cin >> n;
        
        x += dx[n];
        y += dy[n];

        if (x < 0 || y < 0 || x >= r || y >= c) {
            x -= dx[n];
            y -= dy[n];
            continue;
        }

        // 0 위, 1 뒤, 2 우, 3 좌, 4 앞, 5 바닥
        // 동
        if (n == 1) {   // 0 2 3 5
            int top = dice[0], right = dice[2], left = dice[3], floor = dice[5];
            dice[0] = left; // 좌 -> 위
            dice[2] = top;  // 위 -> 우
            dice[3] = floor; // 바닥 -> 좌
            dice[5] = right; // 우측 -> 바닥
        }
        // 서
        else if (n == 2) {  // 0 2 3 5
            int top = dice[0], right = dice[2], left = dice[3], floor = dice[5];
            dice[0] = right; 
            dice[2] = floor; 
            dice[3] = top; 
            dice[5] = left;
        }
        // 남
        else if (n == 3) {  // 0 1 4 5
            int top = dice[0], back = dice[1], front = dice[4], floor = dice[5];
            dice[0] = front;
            dice[1] = top;
            dice[4] = floor;
            dice[5] = back;
        }
        // 북
        else {  // 0 1 4 5
            int top = dice[0], back = dice[1], front = dice[4], floor = dice[5];
            dice[0] = back;
            dice[1] = floor;
            dice[4] = top;
            dice[5] = front;
        }

        // 지도가 0이면 주사위 바닥의 수가 복사됨
        if (map[x][y] == 0) {
            map[x][y] = dice[5];
        }
        // 지도가 0이 아니면 지도의 수를 주사위 바닥에 복사하고, 지도는 0이 됨
        else {
            dice[5] = map[x][y];
            map[x][y] = 0;
        }

        cout << dice[0] << '\n';
    }


    return 0;

}