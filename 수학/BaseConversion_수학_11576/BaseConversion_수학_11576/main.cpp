#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define endl "\n"
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num1, num2;
    int count;
    cin >> num1 >> num2;
    cin >> count;
    
    int sum = 0;
    for (int i=count-1; i>=0; i--){
        int num; cin >> num;
        sum += num * pow(num1, i);
    }
    vector<int> ans;
    while(sum){
        ans.push_back(sum%num2);
        sum /= num2;
    }
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
    }
    cout<<endl;
    return 0;
}
