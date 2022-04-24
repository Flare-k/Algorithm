#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;

int N, K;
int checkHp;
struct Node {
    int hp;
    bool exist;
};

deque<Node> dq;

void rotateBelt() {
    dq.push_front(dq.back());
    dq.pop_back();
    if (dq[N - 1].exist == true) dq[N - 1].exist = false;  // 로봇 내리기
}

void liftBox() {
    if (dq[0].hp > 0 && !dq[0].exist) {
        dq[0].hp--;
        dq[0].exist = true;
        if (dq[0].hp == 0) checkHp++;
    }
}

void rotateexist() {
    for (int i = N - 2; i >= 0; i--) {
        if (dq[i].exist) {   // 로봇이 올려져 있다면
            if (dq[i + 1].exist == false && dq[i + 1].hp > 0) {
                dq[i + 1].exist = true;
                dq[i + 1].hp--;
                dq[i].exist = false;
                if (dq[i + 1].hp == 0) checkHp++;
            }
        }
    }
    
    if (dq[N - 1].exist == true) dq[N - 1].exist = false;  // 로봇 내리기
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < 2 * N; i++) {
        int num;
        cin >> num;
        dq.push_back({num, false});
    }

    int level = 0;

    while (1) {
        rotateBelt();
        rotateexist();
        liftBox();
        level++;
        if (checkHp >= K) break;
    }
    
    cout << level << '\n';

	return 0;
}
