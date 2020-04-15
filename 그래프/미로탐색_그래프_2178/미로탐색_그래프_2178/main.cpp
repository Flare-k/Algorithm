#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000+1;
int arr[MAX][MAX];
int a,b;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool check[MAX][MAX];

struct idx{
    int x, y;
};
queue<idx> q;

void BFS(){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(0 <= nx && nx < b && 0 <= ny && ny < a){
                if(arr[nx][ny]==1){
                    arr[nx][ny] = arr[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}


int main(){
    
    cin>>a>>b;
    for(int i=0; i<a; i++){ //세로
        string temp;
        cin>>temp;
        for(int j=0; j<b; j++){ //가로
            arr[i][j] = temp[j] - '0';
            q.push({i,j});
        }
    }
    BFS();
    int result=0;
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(result < arr[i][j])
                result = arr[i][j];
        }
    }

    cout<<result-1<<'\n';
    
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}


