#include <iostream>

using namespace std;

const int MAX = 101;
int map[MAX][MAX];
int N, M;
int r, c;
int cnt;
int dir;

int main(){

    cin >> N >> M;
    cin >> r >> c >> dir;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while(1) {
        int dx[] = {-1, 0, 1, 0};   //북0 동1 남2 서3
        int dy[] = {0, 1, 0, -1};

        if (map[r][c] == 0) {
            map[r][c] = 2;
            cnt += 1;
        }

        int check = 0;

        for (int i = 0; i < 4; i++) { // dir:0-> -1(3) - 2 - 1 - 0
            dir -= 1;

            if(dir < 0)
                dir = 3;

            int nx = r + dx[dir];
            int ny = c + dy[dir];

            if (map[nx][ny] == 0) {
                r = nx;
                c = ny;
                check = 1;
                break;
            }
        }

        if (check == 1)
            continue;
        //후진의 경우
        int tmp_dir = dir - 2;
        
        if(tmp_dir == -2)
            tmp_dir = 2;
        if(tmp_dir == -1)
            tmp_dir = 3;
        
        r += dx[tmp_dir];
        c += dy[tmp_dir];
        
        if(map[r][c] == 1)
            break;
    }

    cout << cnt << '\n';
    
    return 0;
}
