#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int idx = 0;
    vector<int> score;

    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] == 'S') {
            score[idx - 1] = pow(score[idx - 1], 1);
        }
        else if (dartResult[i] == 'D') {
            score[idx - 1] = pow(score[idx - 1], 2);
        }
        else if (dartResult[i] == 'T') {
            score[idx - 1] = pow(score[idx - 1], 3);
        }
        else if (dartResult[i] == '*') {
            score[idx - 1] *= 2;
            if (idx > 1)
                score[idx - 2] *= 2;
        }
        else if (dartResult[i] == '#') {
            score[idx - 1] *= (-1);
        }
        else {
            if (dartResult[i + 1] == '0') {
                score.push_back(10);
                i++;
            }
            else {
                score.push_back(dartResult[i] - '0');
            }
            idx++;
        }
    }

    for (int i = 0; i < score.size(); i++) {
        answer += score[i];
    }
    
    return answer;
}

int main() {
    string dartResult = "1S2D*3T";
    cout << solution(dartResult) << endl;

    return 0;
}


/*
 for(int i=0; i<dartResult.size(); i++){
     if(isdigit(dartResult[i])){
         string num = "";    //숫자로 이뤄진 문자일 경우를 위해 임의의 빈 문자 생성
         num += dartResult[i];   //숫자라면 해당 문자를 숫자로 바꿔준다.
         answer += stoi(num);
     }
 }
 */
