#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

int n;
const int MAX = 101;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int arr[MAX][MAX];
bool visit[MAX][MAX];

void DFS(int x, int y, int limit){
    visit[x][y] = true;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
        if (arr[nx][ny] > limit && !visit[nx][ny]){
            DFS(nx, ny, limit);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 입력하면서 최소, 최대 데이터 뽑아서 탐색시 반복문의 start, end로 설정하자.
    cin >> n;
    int start = 987654321;
    int end = -1;

    for (int i = 0 ; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            start = min(start, arr[i][j]);
            end = max(end, arr[i][j]);
        }
    }

    int res = 1;
    while (start != end){
        int cnt = 0;
        memset(visit, false, sizeof(visit));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
               if (arr[i][j] > start  && !visit[i][j]) {
                  cnt++;
                  DFS(i, j, start);
               }
            }
        }
        // cout << "point: " << start << ", cnt: "<< cnt << "\n";
        start++;
        res = max(res, cnt);
    }

    cout << res << endl;
    return 0;
}