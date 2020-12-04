#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

const int MAX = 1001;
bool visit[MAX][MAX];
int arr[MAX][MAX];
int col, row;
const int dx[4] = {-1 , 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};   //좌 우 하 상

struct road{
    int x, y;
};  // 좌표를 표현해야하므로 다음과 같은 struct 사용하였다. pair를 사용해도 상관없다고 생각.
queue<road> q;
/*
 경우의 수가 여러 갈래로 갈릴 경우
 가중치에 따라 하나하나 DFS 보다는 같은 레벨의 자식 노드를 모두 탐색하는 BFS가 더 적절하다고 판단.
 */
void BFS(){
    q.push({0, 0});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0 <= nx && nx < row && 0 <= ny && ny < col){
                if(arr[nx][ny] == 1){
                    arr[nx][ny] = arr[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    
    cin>>row>>col;
    
    for(int i = 0; i < row; i++){
        string temp; cin >> temp;
        for(int j = 0; j < col; j++){
            arr[i][j] = temp[j]-'0';
        }
    }   // 2차원 배열 셋팅
    BFS();
    // 확인용 출력문
    /*
    cout << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }*/
    //cout << endl;
    cout << arr[row-1][col-1] << endl;
    return 0;
}
