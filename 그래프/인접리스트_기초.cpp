#include <iostream>
#include <vector>
using namespace std;
/*
 인접리스트의 구현
 
 1-----2
 |\   /
 | \ /
 3  4---5
  \____/
 
 1: 2 3 4
 2: 1 4
 3: 1 5
 4: 1 2 5
 5: 3 4
 */
const int MAX = 100;

int main() {
    // 각각의 정점에 대해 벡터가 필요함.
    vector<int> myGraph[MAX]; //vector<int>가 MAX개 생김.
    int n,m;
    cin>>n>>m;
    
    for(int i=0; i<m; i++){ //간선의 수만큼 입력
        int a,b;
        cin>>a>>b;
        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }
    
    for(int i=1;i<=n; i++){
        cout<<"Node "<<i<<"("<<myGraph[i].size()<<"): ";
        for(int j=0; j<myGraph[i].size(); j++){
            cout<<myGraph[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    return 0;
}
/*
 5 6
 1 2
 1 3
 1 4
 2 4
 3 5
 4 5
 */
