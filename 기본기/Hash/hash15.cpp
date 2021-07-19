#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;

/*
A: 4, -7, -8,  5, -9
B: 5,  1,  1, -8,  9
C: 6,  4, -4,  1,  1
D: 5, -6,  5, -5,  7

이중 포문으로 A, B & C, D의 합 케이스를 모두 구한다.
A + B의 케이스로 나온 값에 대해 해쉬의 값으로 갯수를 입력해준다.
C + D의 마이너스 케이스가 A + B에 존재한다면 그 값을 결과값에 + 해준다.

하나씩 더해서 0이 되는 케이스 구하기
*/
vector<int> arr[4] = {{4, -7, -8,  5, -9},
                      {5,  1,  1, -8,  9},
                      {6,  4, -4,  1,  1},
                      {5, -6,  5, -5,  7}};


int main() {

    int idx = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int sum = arr[idx][i] + arr[idx + 1][j];
            m[sum]++;
        }
    }

    idx += 2;

    int total = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int sum = arr[idx][i] + arr[idx + 1][j];
            if (m.count(-sum) > 0) total += m[-sum];
        }
    }

    cout << total;

    return 0;
}