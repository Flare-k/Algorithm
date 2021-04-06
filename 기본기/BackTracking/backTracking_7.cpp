#include <iostream>
#include <stack>
using namespace std;

// 타겟 넘버로 만들기 위해 왼쪽 스핀, 오른쪽 스핀, 역 스핀이 최소 몇 번 필요한가
// 스핀이 중요한게 아니므로 스핀은 그냥 하드코딩 해둔다고 가정
// 최대 다섯번 안에 만들 수 있을까?

/*
Branch = 3
Level = 5
*/

int vect[4] = {4, 7, 9, 1};
int target[4] = {1, 9, 7, 4};

void left();
void right();
void reverse();

int minSec = 21e8;

int isGood() {
    for (int i = 0; i < 4; i++) {
        if (vect[i] != target[i]) return 0;
    }

    return 1;
}

void run(int level) {
    if (isGood() == 1) {
        cout << "OK" << '\n';
        return;
    }

    if (level == 5) return;
    

    int back[4];
    memcpy(back, vect, 16);

    left();
    run(level + 1);
    // right();
    memcpy(vect, back, 16);

    right();
    run(level + 1);
    // left();
    memcpy(vect, back, 16);

    reverse();
    run(level + 1);
    // reverse();
    memcpy(vect, back, 16);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    run(0);

    // cout << minSec << "번" << '\n';

    return 0;
}

void left() {
    int back = vect[0];
    vect[0] = vect[1];
    vect[1] = vect[2];
    vect[2] = vect[3];
    vect[3] = back;
}

void right() {
    int back = vect[3];
    vect[3] = vect[2];
    vect[2] = vect[1];
    vect[1] = vect[0];
    vect[0] = back;
}

void reverse() {
    stack<int> st;
    for (int i = 0; i < 4; i++) {
        st.push(vect[i]);
    }
    
    for (int i = 0; i < 4; i++) {
        vect[i] = st.top();
        st.pop();
    }
}