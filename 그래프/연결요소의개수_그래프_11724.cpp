#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000;
vector<int> point[MAX];
bool visit[MAX];

void dfs(int node){
    visit[node] = true;
    
    for(int i = 0; i < point[node].size(); i++){
        int next = point[node][i];
        if(visit[next] == false)
            dfs(next);
    }
}

int main() {
    int n,m;
    cin >> n >> m; //정점, 간선
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        point[a].push_back(b);
        point[b].push_back(a);
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            dfs(i); //첫 노드가 1이 아닐수도있으므로..
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
