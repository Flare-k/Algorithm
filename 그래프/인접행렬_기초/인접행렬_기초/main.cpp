/*
 인접행렬을 이용한 그래프의 구현
 ex,
 5 6 (정점의 갯수, 간선의 갯수)
 -------------------------
 1 2
 1 3
 1 4
 2 4
 4 5
 3 5
 1-----2
 |\    |
 | \   |
 3  \ /
 |   4
 | /
 5
 */
#include <iostream>
using namespace std;
const int MAX = 10;

//Q1. 정점 x와 y가 연결이 돼 있는가? (YES / NO)
bool isConnected(int myGraph[MAX][MAX], int x, int y){
    //myGraph에서 x와 y가 연결이 되어 있으면 true, 아니면 false를 반환
    //삼항연산자 : 조건 ? 값1 : 값2
    // O(1)
    return myGraph[x][y] == 1 ? true : false;
}

//Q2. 정점 x와 연결된 정점을 모두 출력하라.
void getAdj(int myGraph[MAX][MAX], int n, int x){
    //Adjacent node = 인접한 노드
    // O(n)
    for(int i=1; i<=n; i++){
        if(myGraph[x][i] == 1)
            cout<<i<<' ';
    }
    cout<<'\n';
}

int main() {
    int n,m;        //n:정점의 개수, m:간선의 개수
    int myGraph[MAX][MAX] = {0,};
    
    cin>>n>>m;
    for(int i=0; i<m; i++){ //간선의 정보를 담을 것
        int a,b;
        cin>>a>>b; //a와 b가 연결이 돼 있다.
        myGraph[a][b] = 1;
        myGraph[b][a] = 1;
    }
    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<myGraph[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    //isConnected
    cout<<isConnected(myGraph, 1, 2)<<'\n'; // 1
    cout<<isConnected(myGraph, 1, 5)<<'\n'; // 0
    
    //getAdj
    getAdj(myGraph, n, 2); // 1 4
    getAdj(myGraph, n, 4); // 1 2 4
    
    return 0;
}
