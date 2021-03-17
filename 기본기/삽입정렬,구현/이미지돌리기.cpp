#include <iostream>
#include <vector>
using namespace std;

/*
N, K를 입력받고 NxN인 이미지를 만든다.
입력 받은 K 만큼 오른쪽으로 돌린 결과 나타내기
*/

// 이미지를 오른쪽으로 돌려 tmp에 저장하고 다시 board에 갱신
void turnRight(int N, vector<vector<int>>& board) {
    vector<vector<int>> tmp(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = board[N - j - 1][i];
        }
    }

    board = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> board(N, vector<int>(N));

    // 이미지 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 이미지 돌리기
    while (K--) {
        turnRight(N, board);
    }

    // 이미지 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}