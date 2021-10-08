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
bool visit[MAX][MAX];
vector<vector<Node>> blocks;

void findBlock(int x, int y, int n, vector<Node>& block, vector<vector<int>> table) { 
    if (visit[x][y]) return;
    if table[x][y] == 0) return;

    visit[x][y] = true;
    block.push_back({x, y});

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        findBlock(nx, ny, n, block, table);
    }
}

bool solve(vector<vector<int>>& game_board, vector<Node> block) {
    int n = game_board.size();
    for (int r = -n+1; r < n; r++) {
        for (int c = -n+1; c < n; c++) {
            vector<Node> fitBlock;

            for (auto b : block) {
                fitBlock.push_back({b.x + r, b.y + c});
            }

            int cnt = 0;
            for (int i = 0; i < fitBlock.size(); i++) {
                Node now = fitBlock[i];

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

                    if (fit == false) break;
                }

                if (fit == false) {
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
    int n = table.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == 1) {
                vector<Node> block;
                findBlock(i, j, n, block, table);
                if (block.size()) blocks.push_back(block);
            }
        }
    }

    vector<vector<int>> rotate_board(n, vector<int>(n, 0));
    vector<bool> checkBlock(blocks.size(), false);
    int answer = 0;

    for (int i = 0; i < 4; i++) {
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                rotate_board[r][c] = game_board[c][n-r-1];
            }
        }

        for (int j = 0; j < blocks.size(); j++) {
            if (!checkBlock[j] && solve(rotate_board, blocks[j])) {
                answer += blocks[j].size();
                checkBlock[j] = true;
            }
        }

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                game_board[r][c] = rotate_board[r][c];
            }
        }
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