#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> q;
    int num; cin>>num;
    for(int i=1; i<=num; i++){
        q.push(i);
    }
    vector<int> result;
    
    while(!q.empty()){
        int tmp = q.front();    //버리기
        q.pop();
        result.push_back(tmp);
        int next = q.front();
        q.pop();
        q.push(next);
    }
    for(int i=0; i<result.size(); i++)
        cout<<result[i]<<' ';
    cout<<'\n';
    return 0;
}
