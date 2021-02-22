#include <iostream>
#include <string>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    // 럭키 스트레이트는 점수가 특정 조건을 만족할 때만 발동됨 -> 점수 N의 반을 나누어 왼쪽 오른쪽 자리수의 각 합이 동일한 상황일 때.
    // 자릿수는 항상 짝수이다.
    string N;
    cin >> N;

    int len = N.length();

    int left = 0;
    int right = 0;

    for (int i = 0; i < len / 2; i++) {
        left += (N[i] - '0');
    }

    for (int i = len / 2; i < len; i++) {
        right += (N[i] - '0');
    }

    if (left == right) {
        cout << "LUCKY";
    }
    else {
        cout << "READY";
    }

    return 0;
}