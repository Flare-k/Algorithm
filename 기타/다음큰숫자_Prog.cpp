#include <iostream>
#include <string>
#include <vector>
using namespace std;

int changeBinary(int n) {
   int cntOne = 0;  // 2진수로 변환시 1인 경우 카운트 증가

    while (n) {
        if (n % 2 == 1) {
            cntOne++;
        }
        n /= 2;
    }
    return cntOne;  // 1의 개수 리턴
}

int solution(int n) {
    int answer = 0;
    
    for (int i = n + 1;; i++) {
        if (changeBinary(n) == changeBinary(i)) {
            answer = i;
            break;
        }
    }
    return answer;
}