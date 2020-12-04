#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 1000 + 1;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int cnt = 0, a, b;
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<int> result;

void DFS(int x, int y){
    visit[x][y] = true;
    
    for(int i = 0; i < 8; i++){
        int next_X = x + dx[i];
        int next_Y = y + dy[i];

        if(next_X < 0 || b <= next_X || next_Y < 0 || a <= next_Y) continue;
        
        if(arr[next_X][next_Y] == 1 && !visit[next_X][next_Y]){
            DFS(next_X, next_Y);
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> a >> b && a != 0 && b != 0){
        for(int i = 0; i < b; i++){
            for(int j = 0; j < a; j++){
                cin >> arr[i][j];
            }
        }

        for(int i = 0; i < b; i++){
            for(int j = 0; j < a; j++){
                if(arr[i][j] == 1 && !visit[i][j]){
                    DFS(i, j);
                    cnt++;
                }
                
            }
        }
        cout << cnt << '\n';
        cnt = 0;
        memset(visit, false, sizeof(visit));
        memset(arr, 0, sizeof(arr));
    }
    
    return 0;
}
