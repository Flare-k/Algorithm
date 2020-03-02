#include <iostream>
using namespace std;

bool c[10]; int a[10];

void go(int index, int start, int n, int m){
    if(index == m){
        for(int j=0; j<m; j++){
            cout<<a[j]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start; i<=n; i++){
        if(c[i]) continue;
        c[i] = true; a[index] = i;
        go(index+1, i+1, n, m); // 4 2
        c[i] = false;
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    go(0,1,n,m);
    return 0;
}
