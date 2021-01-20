#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
   
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i=0; i<citations.size(); i++){
        if(citations[i] <= answer)
            break;
        
        answer++;
    }
    
    return answer;
}
int main(){
    vector<int> citations = {3,0,6,1,5};
    cout<<solution(citations)<<'\n';
    
    return 0;
}
