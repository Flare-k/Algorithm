#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 101
using namespace std;

struct Node {
    int num, cnt;
};
int board[MAX][MAX];
int N, M, r, c, k;
int row, col;
int answer;
map<int, int> m;
vector<Node> arr;

bool cmp(Node& A, Node& B) {
    if (A.cnt < B.cnt) return true;
    else if (A.cnt == B.cnt) {
        if (A.num < B.num) return true;
    }
    return false;
}

void run() {
    int newRow = row, newCol = col;

    if (row >= col) {
        for (int i = 1; i <= row; i++) {
            m.clear();
            arr.clear();
            for (int j = 1; j <= col; j++) {
                if (board[i][j] == 0) continue;
                m[board[i][j]]++;
                board[i][j] = 0;
            }

            for (auto iter = m.begin(); iter != m.end(); iter++) {
                arr.push_back({iter->first, iter->second});
            }
            
            int size = arr.size() * 2;
            int idx = 0;
            newCol = max(size, newCol);
            sort(arr.begin(), arr.end(), cmp);

            for (int j = 1; j <= size; j += 2) {
                board[i][j] = arr[idx].num;
                board[i][j + 1] = arr[idx].cnt;
                idx++;
            }

            for (int j = newCol; j >= size + 1; j--) {
                board[i][j] = 0;
            }

        }
    }
    else {
        for (int j = 1; j <= col; j++) {
            m.clear();
            arr.clear();
            for (int i = 1; i <= row; i++) {
                if (board[i][j] == 0) continue;
                m[board[i][j]]++;
                board[i][j] = 0;
            }

            for (auto iter = m.begin(); iter != m.end(); iter++) {
                arr.push_back({iter->first, iter->second});
            }
            
            int size = arr.size() * 2;
            int idx = 0;
            newRow = max(size, newRow);
            sort(arr.begin(), arr.end(), cmp);

            for (int i = 1; i <= size; i += 2) {
                board[i][j] = arr[idx].num;
                board[i + 1][j] = arr[idx].cnt;
                idx++;
            }

            for (int i = newRow; i >= size + 1; i--) {
                board[i][j] = 0;
            }
        }
    }

    row = newRow;
    col = newCol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> board[i][j];
        }
    }

    int time = 0;
    row = 3; 
    col = 3;

    if (board[r][c] == k) cout << time << '\n';
    else {
        while (time <= 100) {
            run();
            time++;
            
            if (board[r][c] == k) {
                cout << time << '\n';
                break;
            }
        }

        if (time > 100) cout << -1 << '\n';
    }

    return 0;
}