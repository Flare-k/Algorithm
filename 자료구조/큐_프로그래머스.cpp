#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//탑
vector<int> solution(vector<int> temp) {
    vector<int> answer;
    stack<int> tower;

    bool check = true;

    for (int j = temp.size() - 1; j >= 0; j--) {    //전체반복
        for (int i = j - 1; i >= 0; i--) {     //비교대상
            if (temp[i] > temp[j]) {
                tower.push(i + 1);
                check = false;
                break;
            }
        }
        if (check) {
            tower.push(0);
        }
        check = true;
    }

    while (!tower.empty()) {
        answer.push_back(tower.top());
        tower.pop();
    }
    
    return answer;
}


int main() {
    vector<int> temp{6, 9, 5, 7, 4};
    
    for (int i = 0; i < solution(temp).size(); i++) {
        cout << solution(temp)[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
