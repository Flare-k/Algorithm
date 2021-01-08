#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 51;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
int room[MAX][MAX]; // 방의 정보
int roomTmp[MAX][MAX];  // 임시 방의 정보
queue<pair<int, int>> q;

void runFresher(int r, int c){
    int first = 0; //위쪽 공기청정기
    for (int i = 0 ; i < r; i++){
        if (room[i][0] == -1){
            first = i;
            break;
        }
    }
    for (int i = first - 1; i >= 1; i--){
        room[i][0] = room[i - 1][0];
    }
    for (int i = 0; i < c - 1; i++){
        room[0][i] = room[0][i + 1];
    }
    for (int i = 0; i < first; i++){
        room[i][c - 1] = room[i + 1][c - 1];
    }
    for (int i = c - 1; i >= 2; i--){
        room[first][i] = room[first][i - 1];
    }
    room[first][1] = 0;
    
    //아래쪽 공기청정기
    int second = first + 1;  
    for (int i = second + 1; i < r - 1; i++) {
        room[i][0] = room[i + 1][0];
    }
    for (int i = 0; i < c - 1; i++) {
        room[r - 1][i] = room[r - 1][i + 1];
    }
    for (int i = r - 1; i >= second + 1; i--) {
        room[i][c - 1] = room[i - 1][c - 1];
    }
    for (int i = c - 1; i >= 2; i--) {
        room[second][i] = room[second][i - 1];
    }
    room[second][1] = 0;
}

void BFS(int r, int c){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int res = room[x][y] / 5;
        
        q.pop();

        if (res == 0) continue;

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < r && 0 <= ny && ny < c && room[nx][ny] != -1) {
                roomTmp[nx][ny] += res;
                room[x][y] -= res;
            }
        }

    }

    for (int i = 0; i < r; i++) {
       for (int j = 0; j < c; j++) {
          room[i][j] += roomTmp[i][j];
       }
    }
    
    // 공기청정기 ON!
    runFresher(r, c);
    
    for (int i = 0; i < r; i++) {
       for (int j = 0; j < c; j++) {
          if (room[i][j] != 0 && room[i][j] != -1) {
             q.push({i, j});
          }
       }
    }

    memset(roomTmp, 0, sizeof(roomTmp));

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r, c, t;
    cin >> r >> c >> t;
    
    for (int i = 0; i < r; i++){
       for (int j = 0; j < c; j++) {
           cin >> room[i][j];
           roomTmp[i][j] = 0;

           if (room[i][j] != 0 && room[i][j] != -1) {
              q.push({i, j});
           }

       }
    }

    while (t--){
        BFS(r, c);  // 미세먼지 확산 & 공기청정기 T번
    }

    int ans = 0;
    for (int i = 0; i < r; i++) {
       for (int j = 0; j < c; j++) {
          ans += room[i][j];
       }
    }
    cout << ans + 2 << '\n';    // 공기청정기 -1 두번을 상쇄시키기 위해 +2

    return 0;
}