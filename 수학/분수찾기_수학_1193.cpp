#include <iostream>
using namespace std;

const int MAX = 10000000 + 1;
int arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 1. 오른쪽으로 한칸 진행
    // 2. 왼쪽아래 대각선으로 반복 직진 -> 만약 끝에 도달하면? 아래 행으로 이동
    // 3. 오른쪽 위 대각선으로 반복 직진 -> 만약 끝에 도달하면? 오른쪽으로 한칸
    // 진행
    int X;
    cin >> X;

    int a = 0;
    int i = 1;
    
    for (; a < X; i++) {
        a += i;
    }
    i--;  // i/1부터 1/i까지 그룹은 i 개로 이루어져 있다.

    int numerator;
    int denominator;
    int t = a - X;
    
    if (i % 2 == 1) {
        numerator = 1 + t;
        denominator = i - t;
    }
    else {
        numerator = i - t;
        denominator = 1 + t;
    }

    cout << numerator << "/" << denominator << '\n';
}
