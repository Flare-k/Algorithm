#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<pair<int, int>> pnt;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        pnt.push_back(make_pair(a, b));
    }
    sort(pnt.begin(), pnt.end());
    for(int i=0; i<n; i++){
        cout<<pnt[i].first<<" "<<pnt[i].second<<'\n';
    }
    
    return 0;
}
