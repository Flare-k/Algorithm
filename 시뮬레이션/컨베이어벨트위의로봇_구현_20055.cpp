#include <iostream>
#include <vector>
using namespace std;

/*
    내구도가 닳는 경우
    로봇이 칸에 올라갈 때, 로봇이 칸에서 이동할 때
*/

struct Block {
    int hp;
    bool robot;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    Block blocks[N * 2 + 1];
    Block tmps[N * 2 + 1];

    // 내구도
    int h;
    for (int i = 1; i <= N  * 2; i++) {
        cin >> blocks[i].hp;
        blocks[i].robot = false;
    }

    int cnt = 0;
    int iter = 1;
    while (iter++) {
        // 1단계
        tmps[1] = blocks[N * 2];    // 하나 올리기
        for (int i = 2; i <= N * 2; i++) {
            tmps[i] = blocks[i - 1];
        }
        for (int i = 1; i <= N * 2; i++) {
            blocks[i] = tmps[i];
        }   // blocks로 다시 복사
        if (blocks[N].robot == true) blocks[N].robot = false; // 로봇 내리기

        // 2단계
        for (int i = N - 1; i >= 1; i--) {
            if (blocks[i].robot) {   // 로봇이 올려져 있다면
                if (blocks[i + 1].robot == false && blocks[i + 1].hp > 0) {
                    blocks[i + 1].robot = true;
                    blocks[i + 1].hp--;
                    blocks[i].robot = false;
                    if (blocks[i + 1].hp == 0) cnt++;
                }
            }
        }
        if (blocks[N].robot == true) blocks[N].robot = false;  // 로봇 내리기

        // 3단계
        if (blocks[1].hp > 0 && !blocks[1].robot) {
            blocks[1].robot = true;
            blocks[1].hp--;
            if (blocks[1].hp == 0) cnt++;
        }

        // 4단계
        if (cnt >= K) {
            break;
        }

    }

    cout << iter - 1;

    return 0;
}