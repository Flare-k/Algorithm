#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> answer;
vector<vector<int>> arrCopy;    // 전역으로 복사하게 되면 시간초과를 피할 수 있다.
/*
전역변수를 사용하면 값들을 복사해오는데 드는 쓸데없는 시간을 절약해주는 것 뿐만 아니라
파라미터로 변수들을 넘겨주는 수고스러움도 덜 수가 있다.

출처: https://sarah950716.tistory.com/2 [주니어 개발자의 대나무숲]
*/

void devide(int x, int y, int size) {
     int firstElem = arrCopy[x][y];
     bool flag = false;

     for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arrCopy[i][j] != firstElem) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    
    if (!flag) {
        answer.push_back(firstElem);
    }
    else {
        for (int i = x; i < x + size; i += (size / 2)) {
            for (int j = y; j < y + size; j += (size / 2)) {
                devide(i, j, size / 2);
            }
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    arrCopy = arr;

    devide(0, 0, arr.size());

    vector<int> result(2);
    sort(answer.begin(), answer.end());

    for (int num : answer) {
        result[num]++;
    }

    return result;
}

int main() {
    vector<int> ans = solution({{1, 1, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 1},
                                {1, 1, 1, 1}
                                });
    
    for (int num : ans) {
        cout << num << ' ';
    }

    return 0;
}