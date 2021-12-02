#include <iostream>
using namespace std;

int dice[10];
int horse[4];
int board[35];
int turn[35];
bool exist[35];
int score[35];
int answer = 0;

void run(int cnt, int sum) {
    if (cnt == 10) {
        if (sum > answer) answer = sum;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int prev = horse[i];
        int now = prev;
        int move = dice[cnt];

        if (turn[now] > 0) {
            now = turn[now];
            move--;
        }

        while (move--) {
            now = board[now];
        }

        if (now != 21 && exist[now]) continue;

        exist[prev] = false;
        exist[now] = true;
        horse[i] = now;

        run(cnt + 1, sum + score[now]);

        horse[i] = prev;
        exist[now] = false;
        exist[prev] = true;
    }
}

void init() {
    // board
    for (int i = 0; i < 21; i++) {
        board[i] = i + 1;
    }
    board[21] = 21;

    for (int i = 22; i < 27; i++) {
        board[i] = i + 1;
    }
    board[27] = 20;
    
    board[28] = 29; board[29] = 30; board[30] = 25;
    board[31] = 32; board[32] = 25;

    // turn
    turn[5] = 22; turn[10] = 31; turn[15] = 28; turn[25] = 26;

    // score
    for (int i = 0; i < 21; i++) {
        score[i] = i * 2;
    }
    score[22] = 13; score[23] = 16; score[24] = 19;
    score[31] = 22; score[32] = 24; score[28] = 28;
    score[29] = 27; score[30] = 26; score[25] = 25;
    score[26] = 30; score[27] = 35;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();

    for (int i = 0; i < 10; i++) {
        cin >> dice[i];
    }

    run(0, 0);

    cout << answer;

    return 0;
}