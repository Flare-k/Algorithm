#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 100001;
int visited[MAX];
int group[MAX];
bool check[MAX];
int arr[MAX];
int cnt=0;

void dfs(int start){
    if(check[start] == true || visited[start] == -1) return;
    
        if(visited[start] == 0)
            visited[start] = 1;
        else if(visited[start] == 1){
            check[start] = true;
            cnt++;
        }
    dfs(arr[start]);
    
    visited[start] = -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    
    while(n--){
        int a; cin>>a;
       
        for(int i=1; i<=a; i++){
            cin>>arr[i];
            
        }
        for(int j=1; j<=a; j++){
            if(visited[j]==0)
                dfs(j);
        }
        cout<<a-cnt<<'\n';
        
        memset(visited, 0, sizeof(visited));
        memset(group, 0, sizeof(group));
        memset(check, false, sizeof(check));
        memset(arr, 0, sizeof(arr));
        cnt = 0;
    }
    return 0;
}
