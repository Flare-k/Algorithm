#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<int> hansu;

    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(0 < i && i < 100)
            cnt++;
        else if(i>=1000)
            break;
        else{
            int f,s,t;
            t = i/100;
            s = (i%100)/10;
            f = i%10;
            if(t-s == s-f)
                cnt++;
        }
        
    }
    
    
    cout<<cnt<<'\n';
    
    
    return 0;
}
