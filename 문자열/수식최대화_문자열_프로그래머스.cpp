#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

// +(1), -(2), *(3)

long long solution(string expression) {
    long long answer = 0;

    vector<long long> tmp;
    vector<int> oper, location;
    set<int> exp;
    string num = "";

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            tmp.push_back(stoi(num));

            if (expression[i] == '+') {
                location.push_back(1);
                exp.insert(1);
            }
            else if (expression[i] == '-') {
                location.push_back(2);
                exp.insert(2);
            }
            else {
                location.push_back(3);
                exp.insert(3);
            }

            num = "";
        }
        else {
            num += expression[i];
        }
    }
    // 마지막 케이스
    tmp.push_back(stoi(num));

    for (int n : exp) {
        oper.push_back(n);
    }
    sort(oper.begin(), oper.end());

    do {
        vector<long long> tmpNum = tmp;
        vector<int> tmpLocation = location;

        for (int exps : oper) {
            for (int i = 0; i < tmpLocation.size(); i++) {
                if (exps == tmpLocation[i]) {
                    if (tmpLocation[i] == 1) {  // +
                        tmpNum[i] = tmpNum[i] + tmpNum[i + 1];
                    }
                    else if (tmpLocation[i] == 2) { // -
                        tmpNum[i] = tmpNum[i] - tmpNum[i + 1];
                    }
                    else {
                        tmpNum[i] = tmpNum[i] * tmpNum[i + 1];
                    }

                    tmpNum.erase(tmpNum.begin() + i + 1);   // 현재 tmpNum 위치에 갱신했기 때문에 뒤에 있는 요소를 제거해준다.
                    tmpLocation.erase(tmpLocation.begin() + i); // 현재 요소를 제거한다
                    i--;
                }
            }
        }

        if (answer < abs(tmpNum[0])) answer = abs(tmpNum[0]);

    } while(next_permutation(oper.begin(), oper.end()));

    return answer;
}


int main() {
    
    long long exp = solution("100-200*300-500+20");

    cout << exp;
    
    return 0;
}