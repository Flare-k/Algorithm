#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int x, y;
};
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX = 51;
vector<vector<int>> cptable;
vector<vector<Node>> blocks;
bool visit[MAX][MAX];
int n;

// 시계방향
void rotatePuzzle(vector<vector<int>>& rotate, vector<vector<int>>& game_board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotate[i][j] = game_board[j][n-i-1];
        }
    }
}

void findBlock(int x, int y, vector<Node>& block) { 
    if (visit[x][y] || cptable[x][y] == 0) return;

    visit[x][y] = true;
    block.push_back({x, y});

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        findBlock(nx, ny, block);
    }
}

bool solve(vector<vector<int>>& game_board, vector<Node> block) {
    for (int r = -n+1; r < n; r++) {
        for (int c = -n+1; c < n; c++) {
            vector<Node> fitBlock;

            for (auto b : block) {
                fitBlock.push_back({b.x + r, b.y + c});
            }

            int cnt = 0;
            for (int idx = 0; idx < fitBlock.size(); idx++) {
                Node now = fitBlock[idx];

                if (now.x < 0 || now.y < 0 || now.x >= n || now.y >= n) break;
                if (game_board[now.x][now.y] == 1) break;
                cnt++;
            }

            if (cnt == fitBlock.size()) {
                bool fit = true;

                for (auto f : fitBlock) {
                    game_board[f.x][f.y] = 1;
                }

                for (int idx = 0; idx < fitBlock.size(); idx++) {
                    Node now = fitBlock[idx];

                    for (int d = 0; d < 4; d++) {
                        int nx = now.x + dx[d];
                        int ny = now.y + dy[d];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if (game_board[nx][ny] == 0) {
                            fit = false;
                            break;
                        }
                    }

                    if (!fit) break;
                }

                if (!fit) {
                    for (auto f : fitBlock) {
                        game_board[f.x][f.y] = 0;
                    }
                }
                else return true;
            }
        }
    }

    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {

    cptable = table;

    n = table.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == 1) {
                vector<Node> block;
                findBlock(i, j, block);
                if (block.size() > 0) blocks.push_back(block);
            }
        }
    }

    vector<vector<int>> rotateBoard(n, vector<int>(n, 0));
    vector<bool> checkBlock(blocks.size(), false);
    int answer = 0;

    for (int i = 0; i < 4; i++) {
        rotatePuzzle(rotateBoard, game_board);

        for (int i = 0; i < blocks.size(); i++) {
            bool flag = solve(rotateBoard, blocks[i]);

            if (!checkBlock[i] && flag == true) {
                answer += blocks[i].size();
                checkBlock[i] = true;
            }
        }

        game_board = rotateBoard;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> gb = {{1,1,0,0,1,0},{0,0,1,0,1,0},{0,1,1,0,0,1},{1,1,0,1,1,1},{1,0,0,0,1,0},{0,1,1,1,0,0}};
    vector<vector<int>> tb = {{1,0,0,1,1,0},{1,0,1,0,1,0},{0,1,1,0,1,1},{0,0,1,0,0,0},{1,1,0,1,1,0},{0,1,0,0,0,0}};

    cout << solution(gb, tb) << '\n';

    return 0;
}