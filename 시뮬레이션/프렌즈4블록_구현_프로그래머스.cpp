#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool visit[31][31];

// 2x2 찾기 & 0으로 변환
int checkBlock(int m, int n, vector<string>& b, bool& flag)  {
    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (b[i][j] != '0') {
                if (b[i][j] == b[i][j + 1] && b[i][j] == b[i + 1][j]) cnt++;
                else {
                    cnt = 0;
                    continue;
                }

                if (b[i + 1][j + 1] == b[i][j + 1] && b[i + 1][j + 1] == b[i + 1][j]) cnt++;
                else {
                    cnt = 0;
                    continue;
                }
            }

            if (cnt == 2) {
                for (int a = i; a < i + 2; a++) {
                    for (int b = j; b < j + 2; b++) {
                        visit[a][b] = true;
                    }
                }

                cnt = 0;
                flag = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j]) {
                b[i][j] = '0';
                sum++;
            }
        }
    }

    return sum;
}

// 밑으로 내리기
void pushDown(int m, int n, vector<string>& board) {
    
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j > 0; j--) {
            if (board[j][i] == '0') {
                for (int k = j - 1; k >= 0; k--) {
                    if (board[k][i] != '0') {
                        swap(board[j][i], board[k][i]);
                        break;
                    }
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    bool flag = true;

    while (flag) {
        flag = false;
        memset(visit, false, sizeof(visit));
        answer += checkBlock(m, n, board, flag);
        pushDown(m, n, board);
    }

    return answer;
}


int main() {
    cout << solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"}) << '\n';

    return 0;
}