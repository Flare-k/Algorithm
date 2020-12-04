#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1001;
bool visited[MAX];
vector<int> point[MAX];

void dfs(int node){
    visited[node] = true;
    for(int i = 0; i < point[node].size(); i++){
        int next = point[node][i];
        if(visited[next] == false)
            dfs(next);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin>>testCase;
    
    for(int i = 0; i < testCase; i++){
        int num;
        cin>>num;

        for(int j = 1; j <= num; j++){
            int node;
            cin >> node;
            point[j].push_back(node);
            point[node].push_back(j);
        }
        int ans = 0;
        for(int k = 1; k <= num; k++){
            if(!visited[k]){
                dfs(k);
                ans++;
            }
        }
        cout << ans << '\n';
        memset(visited, false, sizeof(visited));
        memset(point, 0, sizeof(point));
    }
    
    return 0;
}
