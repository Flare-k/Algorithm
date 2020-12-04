#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//1 2 3 4 5 6 7-> 3 4 5 6 7 1 2 -> 6 7 1 2 4 5 -> 2 4 5 7 1 -> 7 1 4 5 -> 5 1 4 ..
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=1; i<=n; i++)
        arr.push_back(i);
    
    
    int idx = k-1;
    int copy_n = n;
    cout<<"<";
    for(int i=0; i<n; i++){
        cout<<arr[idx];
        if(i != n-1)
            cout<<", ";
        else
            cout<<">\n";
        
        arr.erase(arr.begin()+idx);
        idx += (k-1);
        if(--copy_n > 0)
            idx %= copy_n;
    }
    
    return 0;
}
