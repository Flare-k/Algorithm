#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n; // 테스트 케이스 갯수

int main(){
    while(cin>>n && n){
        vector<int> inputvec;
        vector<int> checkvec;
        int num;
        
        
        for(int i=0; i<n; i++){
            cin>>num;
            inputvec.push_back(num);
        }
        
        for(int i=0; i<6; i++){
            checkvec.push_back(1);  //이미 체크한 경우 1
        }
        for(int i=0; i<inputvec.size()-6; i++){
            checkvec.push_back(2);  //체크하지 않은 경우 0 -> 2로 수정함 (0으로하면 sort부분에서 0 0 11...이런식으로 되서 출력이 거꾸로 되기 때문)
        }
        sort(checkvec.begin(), checkvec.end());
        
        do{
            for(int i=0; i<checkvec.size(); i++){
                if(checkvec[i] == 1){
                    cout<<inputvec[i]<<' ';
                }
            }
            cout<<'\n';
            
        }while(next_permutation(checkvec.begin(), checkvec.end()));
        cout<<'\n';
        
    }
    
    
    return 0;
}
