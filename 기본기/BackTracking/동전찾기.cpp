#include <iostream>
using namespace std;

/*
    거스름 돈을 10원, 40원, 50원의 조합으로만 받을 수 있을 때
    n원을 줬을 때 받을 수 있는 거스름 돈의 조합의 최소의 수
    ex, 80원 -> 40원 2개 = 2

    Branch = 10, 40, 50으로 세 개
    Level = 문제상 Level이 곧 잔돈 동전의 갯수.. 최대 8 (10원 8개)
*/

int target = 80; // 80원 타겟이라 가정
int minCnt = 21e8;
int coin[3] = {10, 40, 50};
int path[30];

void run(int level, int changes) {  // changes = 남은 돈
    if (changes < 0) return;
    if (minCnt <= level) return;    // level이 최소 Cnt보다 같거나 크면 이미 최소를 넘어선 경우이므로 그 이후는 탐색하지 않는다. (중요)
    
    if (changes == 0) {
        if (minCnt > level) {
            minCnt = level;
        }

        for (int i = 0; i < 30; i++) {
            if (path[i]) cout << path[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < 3; i++) {
        path[level] = coin[i];  // 디버깅 확인용 path 배열
        run(level + 1, changes - coin[i]);
        path[level] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    run(0, target);

    cout << minCnt << "개\n";

    return 0;
}