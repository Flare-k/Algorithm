#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 20001;
int visited[MAX];
vector<int> arr[MAX];
int red = 1;
int blue = 2;
int n, v, e;
 
void dfs(int start){
    if(!visited[start])
        visited[start] = red;
    for(int i=0; i<arr[start].size(); i++){
        int next = arr[start][i];
        if(!visited[next]){
            if(visited[start] == red){
                visited[next] = blue;
            }
            else if(visited[start] == blue){
                visited[next] = red;
            }
            dfs(next);
        }
    }
}
bool isBipartiteGraph() {
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            int next = arr[i][j];
            if (visited[i] == visited[next]) {
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while(n--){
        for(int i=1; i<=v; i++)
            arr[i].clear();
        memset(visited, false, sizeof(visited));
        cin>>v>>e;
        for(int i=0; i<e; i++){
            int a,b;
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(int i=1; i<=v; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        
        if(isBipartiteGraph())
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    
    return 0;
}

/*
 11
 3 1
 2 3
 3 2
 1 3
 2 3
 4 4
 1 2
 2 3
 3 4
 4 2
 3 2
 2 1
 3 2
 4 4
 2 1
 3 2
 4 3
 4 1
 5 2
 1 5
 1 2
 5 2
 1 2
 2 5
 4 3
 1 2
 4 3
 2 3
 4 4
 2 3
 1 4
 3 4
 1 2
 3 3
 1 2
 2 3
 3 1
 2 1
 1 2

 */
