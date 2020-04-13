#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> bar;
    for(int i=1; i<=64; i++){
        if(64%i == 0)
            bar.push_back(i);
    }
    sort(bar.begin(), bar.end(), greater<int>());
    // 64 32 16 8 4 2 1
    int x;
    cin>>x;
    
    vector<int> result;
    int sum=0;
    int dump=0;
    
    for(int i=0; i<bar.size(); i++){
        if(x >= bar[i]){
            dump = sum;
            sum += bar[i];
            result.push_back(i);
            
            if(sum > x){
                sum = dump;
                result.pop_back();
            }
        }
        if(sum == x){
            cout<<result.size()<<'\n';
            break;
        }
    }
    
    return 0;
}
