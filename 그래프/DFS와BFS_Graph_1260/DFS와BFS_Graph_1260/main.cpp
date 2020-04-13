#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[1001];    //인접리스트.
bool check[1001];
//a와 check는 한 배열이 계속 사용되므로 전역변수로 설정해준다.
/*
 DFS
 1. 나를 방문했다고 처리한다.
 2. 나와 인접한 모든 노드에 대하여 다음을 반복한다.
 3. 만약 인접한 노드를 아직 방문하지 않았다면,
 4. DFS(node)
 5. 방문순서 반환
 (재귀함수 --> 스택사용)
 모든 정점의 개수 + 차수의 합(2*간선의 개수) --> 시간복잡도 = O(V+2E) --> O(V+E)
 */
void dfs(int node){
    check[node] = true; //맨처음 자기자신을 방문.
    cout<<node<<' ';
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];  //현재 node의 인접한 node를 담는다. 즉, x와 y가 연결이 되어 있다.
        if(check[next] == false)
            dfs(next);
    }
    //인접리스트 방법
}   //재귀로 스택역할을 구현함

void bfs(int start){
    queue<int> q;
    memset(check, false, sizeof(check));    //check를 초기화시켜줌
    check[start] = true; q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<' ';
        for(int i=0; i<a[node].size(); i++){
            int next = a[node][i];
            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n,m,start;
    cin>>n>>m>>start;   //n:정점, m:간선, start:시작점
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        //양방향 연결임을 표현해주기 위해
    }
    for(int i=1; i<=n; i++){
        sort(a[i].begin(), a[i].end());
    }//문제에서 원하기 때문에 정렬을 썼을 뿐..
    cout<<"DFS: ";
    dfs(start);
    puts("");
    cout<<"BFS: ";
    bfs(start);
    puts("");
    return 0;
}
/*
 11 13 1
 1 2
 1 4
 2 3
 2 4
 2 11
 3 5
 3 6
 4 9
 5 6
 6 7
 7 8
 8 9
 8 10
 
 9 12 1
 1 2
 1 3
 2 3
 2 4
 2 6
 3 7
 4 5
 4 7
 4 8
 5 6
 7 8
 8 9
 
 */
