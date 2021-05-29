#include <iostream>
#include <string>
#define endl "\n"
using namespace std;
/*
00시 00분 00초 부터 hour시 59분 59초까지의 모든 시각 중에서 3이 하나라도
포함되는 모든 경우의 수를 구하라 > 완전탐색
*/
int hour, cnt = 0;

bool check(int h, int m, int s) {
    if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
      return true;
   // '시'에는 30이 넘는 숫자가 없으므로 나머지 연산만 적용한다.
   return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    cin >> hour;
   
    for (int i = 0; i <= hour; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                if (check(i, j, k)) cnt++;
            }
        }
    }

    cout << cnt << endl;
    
    return 0;
}