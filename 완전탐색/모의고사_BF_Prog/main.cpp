#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> person {{1, 2, 3, 4, 5},
                                {2, 1, 2, 3, 2, 4, 2, 5},
                                {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    vector<pair<int, int>> tmp; // {수포자 번호, 맞힌 문제 수}

    int maxScore = -1;
    for (int i = 0; i < person.size(); i++){
        int correct = 0;
        int size = person[i].size();
        for (int j = 0; j < answers.size(); j++){
           if (person[i][j % size] == answers[j]) {
              correct++;
           }
        }

        maxScore = max(maxScore, correct);
        tmp.push_back({i + 1, correct}); // 수포자 i & 맞힌 문제 수
    }
    
    vector<int> result;
    for (auto& score : tmp) {
        if (maxScore == score.second) { // 최대로 많이 맞힌 문제 수와 수포자가 맞힌 문제 수가 같으면 결과 벡터에 push
            result.push_back(score.first);
        }
    }

    return result;
}
/*
// test용 메인함수
int main() {
    vector<int> ans{1,2,3,4,5};

    for (int i = 0; i < solution(ans).size(); i++){
        cout << solution(ans)[i] << endl;
    } 
    
        
    return 0;
}
*/