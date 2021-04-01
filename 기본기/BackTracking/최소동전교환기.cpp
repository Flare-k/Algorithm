#include <iostream>
#include <vector>
using namespace std;

// 정해진 거스름돈 동전으로 거슬러 줄 수 있는 최소 동전 개수
int coin[3] = {10, 40, 60};
int minCoin = 21e8;

void posMachine(int level, int sum, int target) {
    if (sum > target) return;
    if (level >= minCoin) return;

    if (target == sum) {    // 거슬러 줘야하는 총비용과 동전의 조합이 같다면
        if (minCoin > level) minCoin = level;
        return;
    }

    for (int i = 0; i < 3; i++) {
        posMachine(level + 1, sum + coin[i], target);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tar;
    cin >> tar;

    posMachine(0, 0, tar);

    cout << minCoin;
 
    return 0;
}