#include <iostream> 
#include <algorithm>
#define R_MAX 10001
#define C_MAX 501
using namespace std;  

int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
int map[R_MAX][C_MAX];
int arr[R_MAX][C_MAX];
bool visit[R_MAX][C_MAX];
int R, C, answer;

int run(int x, int y, int num) {
    if (y == C - 1) {
        answer++;
        return 1;
    }

    int flag = 0;
    for (int d = 0; d < 3; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (visit[nx][ny] || map[nx][ny] == 1) continue;

        visit[nx][ny] = true;
        arr[nx][ny] = num;
        flag = max(flag, run(nx, ny, num));
        
        if (flag) break; // 경로가 완성된 경우라면 break
    }

    return flag;
}

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 

    cin >> R >> C;

    char c;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> c;
            if (c == '.') map[i][j] = 0;
            else if (c == 'x') map[i][j] = 1;
        }
    }

    for (int x = 0; x < R; x++) {
        int y = 0;
        arr[x][y] = x + 1;
        run(x, y, x + 1);
    }

    cout << answer;

    return 0; 
}