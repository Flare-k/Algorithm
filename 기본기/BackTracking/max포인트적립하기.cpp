#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Menu {
    int price;
    int pt;
};

Menu menu[5];

int price, n;
int maxCharge = -21e8;
int used[5];

void run(int level, int totalPrice, int totalPoint) {
    if (level == n) {
        int cups = price / totalPrice;    // n 종류의 총 잔 수
        int curPoint = cups * totalPoint;      // 총 잔 수 * 총 포인트

        if (maxCharge < curPoint) {
            maxCharge = curPoint;
        }
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (used[i] == 1) continue;

        used[i] = 1;
        run(level + 1, totalPrice + menu[i].price, totalPoint + menu[i].pt);
        used[i] = 0;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    menu[0] = {500, 30};    // 아메리카노
    menu[1] = {700, 10};    // 수박 쉐이크
    menu[2] = {600, 30};    // 초코 쉐이크
    menu[3] = {300, 40};    // 멜론 주스
    menu[4] = {400, 20};    // 카페라떼

    cin >> price >> n;

    run(0, 0, 0);

    cout << maxCharge;

    return 0;
}