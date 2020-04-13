#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 1000+1;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int cnt,a, b;
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
vector<int> result;


void DFS(int x, int y){
    //cnt += 1;
    visit[x][y] = true;
    
    for(int i=0; i<8; i++){
        int next_X = x+dx[i];
        int next_Y = y+dy[i];
        if(next_X<0 || b<=next_X || next_Y<0 || b<=next_Y) continue;
        if(arr[next_X][next_Y] == 1 && !visit[next_X][next_Y]){
            DFS(next_X, next_Y);
        }
    }
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>a>>b && a!=0 && b!=0){
        for(int i=0; i<b; i++){
            for(int j=0; j<a; j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0; i<b; i++){
            for(int j=0; j<a; j++){
                if(arr[i][j] == 1 && !visit[i][j]){
                    //cnt = 0;
                    DFS(i, j);
                    //result.push_back(cnt);
                    cnt++;
                }
                
            }
        }
        cout<<cnt<<'\n';
        memset(visit, false, sizeof(visit));
    }
    
    return 0;
}
