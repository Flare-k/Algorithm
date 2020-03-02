/*
 Travelling Salesman Problem (TSP)
 1번부터 N번까지 번호가 매겨져있는 도시가 있다.
 한 도시에서 시작해 N개의 모든 도시를 거쳐 다시 원래 도시로 돌아오려고 한다.
 (한 번 갔던 도시로는 다시 갈 수 없다.) // N개의 모든 도시를 1번 씩 방문.. 즉, 순열이용가능
 이 때, 가장 적은 비용을 구하는 문제
 i -> j 비용 = W[i][j]
 추가조건
 W[i][j] = 0  i -> j (x)
 W[i][j] > 0  i -> j (o)
 
 N개의 모든 도시를 1번 씩 방문하는 모든 순서를 만들어서 W를 이용하여 값을 계산하면 된다.
 하지만 순열을 사용하는 문제는 가장 중요한 것이 있다. -> N제한을 살펴봐야한다.
 해당 문제는 2 <= N <= 10으로 N제한이 10이다. 즉 10! = 약 3백만.
 모든 순열을 만드는데 걸리는 시간은 3백만에 N을 곱하는데,, 즉, 1~2초 안에 모든 경우를 만들 수 있다.
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int w[20][20];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int ans = 2147483647;
    cin>>n;
    vector<int> d(n);
    
    for(int i=0; i<n; i++){
        d.push_back(i); //  벡터 d에 0~3이 입력됨
        for(int j=0; j<n; j++){
            cin>>w[i][j];
        }
    }
    
    do{
        bool ok = true; //0의 존재여부
        int sum = 0;
        for(int i=0; i<n-1; i++){
            if(w[d[i]][d[i+1]] == 0) ok = false;
            else sum += w[d[i]][d[i+1]];
        }
        if(ok && w[d[n-1]][d[0]] != 0){ //마지막도시에서 원래도시로 돌아오는
            sum += w[d[n-1]][d[0]];
            if(ans > sum) ans = sum;
        }
    }while(next_permutation(d.begin()+1, d.end())); //벡터 d에는 이미 1~N이 들어가 있는데, next_permu로 모든 순서를 고려..
    
    cout<<ans<<'\n';
    
    return 0;
}
