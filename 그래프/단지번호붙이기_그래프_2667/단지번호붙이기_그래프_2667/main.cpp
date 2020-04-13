#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 1000+1;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int cnt,n;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<int> result;


void DFS(int x, int y){
    cnt += 1;
    visit[x][y] = true;
    
    for(int i=0; i<4; i++){
        int next_X = x+dx[i];
        int next_Y = y+dy[i];
        if(next_X<0 || n<=next_X || next_Y<0 || n<=next_Y) continue;
        if(arr[next_X][next_Y] == 1 && !visit[next_X][next_Y]){
            DFS(next_X, next_Y);
        }
    }
    
}


int main(){
    
    cin>>n;
    for(int i=0; i<n; i++){
        string tmp;
        cin>>tmp;
        for(int j=0; j<n; j++){
            arr[i][j] = tmp[j]-'0';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && !visit[i][j]){
                cnt = 0;
                DFS(i, j);
                result.push_back(cnt);
            }
        }
    }
    sort(result.begin(), result.end());
    cout<<result.size()<<'\n';
    for(int i=0; i<result.size(); i++)
        cout<<result[i]<<'\n';
    return 0;
}
