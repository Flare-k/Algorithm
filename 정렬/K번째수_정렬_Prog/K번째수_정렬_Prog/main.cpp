#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ans;
    
    for(int i=0; i<commands.size(); i++){
        vector<int> tmp;
        for(int j=commands[i][0]; j<=commands[i][1]; j++){
            tmp.push_back(array[j-1]);
        }
        sort(tmp.begin(), tmp.end());
        ans.push_back(tmp[commands[i][2]-1]);
    }
    return ans;
}

int main() {
    vector<int> a = {9,5,8,6,3,7,4,10,11,100,201};
    vector<vector<int>> command = {
                            {2,9,8}
                            ,{4,10,2}
                            ,{1,7,3}
                        };
    for(int i=0; i<solution(a, command).size(); i++){
        cout<<solution(a, command)[i]<<' ';
    }
    cout<<'\n';
    
    return 0;
}
