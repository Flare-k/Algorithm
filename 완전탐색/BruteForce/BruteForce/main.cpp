#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> stu{{1,2,3,4,5},
                            {2,1,2,3,2,4,2,5},
                            {3,3,1,1,2,2,4,4,5,5}};
    vector<int> count={0,0,0};
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == stu[0][i % stu[0].size()])    count[0]++;
        if (answers[i] == stu[1][i % stu[1].size()])    count[1]++;
        if (answers[i] == stu[2][i % stu[2].size()])    count[2]++;
    }
    
    int max = *max_element(count.begin(), count.end());//count 변수의 최대값을 반환하는 함수
    //*max_element(변수.begin(), 변수.end()) -> 해당 변수의 처음과 끝에서 가장 큰 변수를 택함
    for (int i = 0; i < 3; i++){
           if(max == count[i])
               answer.push_back(i + 1);
    }
       return answer;
}


int main(){
    vector<int> answers{1,3,2,4,2};
    solution(answers);
    
    return 0;
}
