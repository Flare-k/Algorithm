#include <iostream>
#include <vector>
using namespace std;
/*
 vector에 1,2,3 넣고.
 해당 vector에 1이 있으면 true 0이면 false
 (1은 공을 대신함)
 */
int main() {
    vector<int> cup{1,0,0};
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        int temp;
        cin>>a>>b;
        temp = cup[a-1];
        cup[a-1] = cup[b-1];
        cup[b-1] = temp;
    }
    for(int i=0; i<cup.size(); i++){
        if(cup[i] == 1)
            cout<<i+1<<'\n';
    }
    
    return 0;
}
