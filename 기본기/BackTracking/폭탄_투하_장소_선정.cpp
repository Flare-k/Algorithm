#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
using namespace std;

struct Node {
    int x;
    int y;
};

char map[4][5];
int check[4][4];
char path[10];
char res[10];
int n;
vector<Node> node;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int maxSum = -21e8;

bool checkMap() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (check[i][j]) return false;
        }
    }

    return true;
}

void run(int level, int sum) {
    int tmp[4][4];
    if (level > n) return;
    
    if (level == n){
        if (checkMap()) {
            if (maxSum < sum) {
                maxSum = sum;
                memcpy(res, path, 10);
            }
        }

        return;
    }

    for (int i = 0; i < node.size(); i++) {
        int x = node[i].x;
        int y = node[i].y;

        if (check[x][y] == 0) continue;

        memcpy(tmp, check, sizeof(check));
        
        int cnt = 1;
        check[x][y] = 0;
        path[level] = map[x][y];

        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (check[nx][ny] == 0) continue;
            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;

            check[nx][ny] = 0;
            cnt++;
        }
        
        run(level + 1, sum + cnt);
        memcpy(check, tmp, sizeof(check));
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(check, 0, sizeof(check));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> map[i][j];
            if (map[i][j] != '_') {
                node.push_back({i, j});
                check[i][j] = 1;
            }
        }    
    }

    cin >> n;

    run(0, 0);

    sort(res, res + 3);
    cout << res[0] << " " << res[1] << " " << res[2];

    return 0;
}