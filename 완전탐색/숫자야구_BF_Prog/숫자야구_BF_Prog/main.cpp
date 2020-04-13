#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    vector<string> ans;
    for(int i=123; i<=987; i++){
        string temp = to_string(i);
        if(temp[0]==temp[1]||temp[1]==temp[2]||temp[2]==temp[0]||temp[0]=='0'||temp[1]=='0'||temp[2]=='0'){
            continue;
        }
        ans.push_back(temp);    //일종의 랜덤값의 경우수를 전수조사하여 집어넣음 (중복제거)
    }
    for(int i=0; i<baseball.size(); i++){
        string tmp = to_string(baseball[i][0]);
        for(int j=ans.size()-1 ; j>=0; j--){
            int strike=0, ball=0;
            for(int k=0; k<3; k++){
                if(tmp[k] == ans[j][k]) strike++;   //자리와 수 모두 같아야 스트라이크
                if(tmp[k] == ans[j][(k+1)%3] || tmp[k] == ans[j][(k+2)%3]) ball++;   // 수만 같으면 볼
            }
            if(strike != baseball[i][1] || ball != baseball[i][2])
                ans.erase(ans.begin()+j);
        }
    }
    
    return ans.size();
}


int main() {
    vector<vector<int>> baseball{{123,1,1},{356,1,0},{327,2,0},{489,0,1}};
    cout<<solution(baseball)<<endl;
    return 0;
}
