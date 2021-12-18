#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> bucket;
int bye = 0;

// 바구니에 집어넣기
void push(int doll) {
    if (bucket.empty() || bucket.back() != doll) {
        bucket.push_back(doll);
    }
    else if (bucket.back() == doll) {
        bye += 2;   // 바구니에 있던 것 + 현재 인형
        bucket.pop_back();
    }
}


// 인형뽑기 기계의 좌표 -> 해당 좌표에 인형의 유무와 좌표 리턴
bool getAxis(int& dx, int& dy, vector<vector<int>> board,  int pos) {
    int len = board.size();

    for (int i = 0; i < len; i++) {
        if (board[i][pos - 1] != 0) {
            dx = i;
            dy = pos - 1;
            return true;
        }
    }

    return false;
}


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    for (int move : moves) {
        int dx, dy;

        if (getAxis(dx, dy, board, move)) {
            push(board[dx][dy]);
            board[dx][dy] = 0;
        }
    }

    return bye;
}

int main() {
    vector<vector<int>> board = {{0,0,0,0,0},
                                {0,0,1,0,3},
                                {0,2,5,0,1},
                                {4,2,4,4,2},
                                {3,5,1,3,1}};

    cout << solution(board, {1,5,3,5,1,2,1,4}) << '\n'; // 4

    return 0;
}