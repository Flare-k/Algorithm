#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int countFamily(int start, int end, vector<int> family[], int dist[]){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if (node == end){
            return dist[node];  // 만약 end번째 사람이라면 촌수 리턴
        }

        for (int i = 0; i < family[node].size(); i++){
            int next = family[node][i];
            if(!dist[next]){
                q.push(next);
                dist[next] += (dist[node] + 1);
            }
        }
    }

    return -1;  // 친척 관계가 전혀 없다면 계산할 수 없으므로 -1 리턴
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int start, end;
    cin >> n; // 전체 사람의 수
    cin >> start >> end; // 촌수를 알고싶은 두 사람의 번호
    cin >> m; // 부모 자식들간의 관계의 수
    
    vector<int> family[n + 1];
    int dist[n + 1];
    fill(dist, dist + (n + 1), 0);

        for (int i = 0; i < m; i++) {
       int x, y;
       cin >> x >> y;  // x는 y의 부모.
       family[x].push_back(y);
       family[y].push_back(x);
    }

    cout << countFamily(start, end, family, dist) << '\n';

    return 0;
}