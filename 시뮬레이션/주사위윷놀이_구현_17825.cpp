#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define MAX 10
using namespace std;

const int board[33][6] = {
//점수, +1 +2 +3 +4 +5칸
    {0, 1, 2, 3, 4, 5},         // 0
    {2, 2, 3, 4, 5, 6},         // 1
    {4, 3, 4, 5, 6, 7},         // 2
    {6, 4, 5, 6, 7, 8},         // 3
    {8, 5, 6, 7, 8, 9},         // 4
    {10, 21, 22, 23, 24, 25},   // 5
    {12, 7, 8, 9, 10, 11},      // 6
    {14, 8, 9, 10, 11, 12},     // 7
    {16, 9, 10, 11, 12, 13},    // 8
    {18, 10, 11, 12, 13, 14},   // 9
    {20, 27, 28, 24, 25, 26},   // 10
    {22, 12, 13, 14, 15, 16},   // 11
    {24, 13, 14, 15, 16, 17},   // 12
    {26, 14, 15, 16, 17, 18},   // 13
    {28, 15, 16, 17, 18, 19},   // 14
    {30, 29, 30, 31, 24, 25},   // 15
    {32, 17, 18, 19, 20, 32},   // 16
    {34, 18, 19, 20, 32, 32},   // 17
    {36, 19, 20, 32, 32, 32},   // 18
    {38, 20, 32, 32, 32, 32},   // 19
    {40, 32, 32, 32, 32, 32},   // 20
    {13, 22, 23, 24, 25, 26},   // 21
    {16, 23, 24, 25, 26, 20},   // 22
    {19, 24, 25, 26, 20, 32},   // 23
    {25, 25, 26, 20, 32, 32},   // 24
    {30, 26, 20, 32, 32, 32},   // 25
    {35, 20, 32, 32, 32, 32},   // 26
    {22, 28, 24, 25, 26, 20},   // 27
    {24, 24, 25, 26, 20, 32},   // 28
    {28, 30, 31, 24, 25, 26},   // 29
    {27, 31, 24, 25, 26, 20},   // 30
    {26, 24, 25, 26, 20, 32},   // 31
    {0, 32, 32, 32, 32, 32}     // 32
};
int dice[MAX];
int answer;

int run(int h) {
    int ret = 0;
    bool visit[33] = {false, };
    int pos[4] = {0, }; // 말의 위치

    for (int turn = 0; turn < MAX; ++turn) {
        int move = dice[turn];
        int horse = (h >> (turn * 2)) & 0x03;   // 2비트마다 들어와있기 때문에 *2해주고 마지막 2비트에 해당하는 값이 horse에 할당된다.
        int& cur = pos[horse];
        int next = board[cur][move];
        int score = board[next][0];

        if (visit[next] && next != 32) {
            return -1;
        }

        ret += score;
        visit[cur] = false;
        visit[next] = true;
        cur = next;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < MAX; i++) {
        cin >> dice[i];
    }

    for (int p = 0; p < (1 << 20); ++p) {   // 2의 20승
        int candidate = run(p);
        answer = max(candidate, answer);
    }

    cout << answer << '\n';

	return 0;
}
