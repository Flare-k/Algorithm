#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int plus = brown+red;
    for(int height=3; ;height++){
        if(!(plus%height)){
            int horizontal = plus/height;
            if((height-2)*(horizontal-2) == red){
                answer.push_back(horizontal);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}

int main() {
    int brown,red;
    cin>>brown>>red;
    for(int i=0; i<solution(brown,red).size(); i++)
        cout<<solution(brown, red)[i]<<' ';
    cout<<'\n';
    
    return 0;
}
