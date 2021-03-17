#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 3},
                                {0, 2, 5, 0, 1},
                                {4, 2, 4, 4, 2},
                                {3, 5, 1, 3, 1}};

vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};  // 움직이는 순서

vector<int> bucket;

int res = 0;

void push(int tar) {
    bucket.push_back(tar);

    if (bucket.size() < 2) return;

    if (bucket[bucket.size() - 2] == bucket[bucket.size() - 1]) {
        res += 2;
        bucket.pop_back();
        bucket.pop_back();
    }
}

int getAxis(int& dx, int& dy, int tar) {
    for (int i = 0; i < 5; i++) {
        if (board[i][tar - 1] != 0) {
            dx = i;
            dy = tar - 1;
            return 1;
        }
    }

    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < moves.size(); i++) {
        int dx, dy;
        int ret = getAxis(dx, dy, moves[i]);
        if (ret == 0) continue;

        push(board[dx][dy]);
        board[dx][dy] = 0;
    }

    cout << res << '\n';
    
    return 0;
}