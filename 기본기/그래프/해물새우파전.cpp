#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x, y, dist;
};

int arr[7][7];
bool check[7][7];
bool checkCpy[7][7];
int r, c;

string BFS(int x, int y, int target) {
    queue<Node> pancake;
    
    memcpy(checkCpy, check, sizeof(check));

    pancake.push({x, y, 0});
    check[x][y] = true;

    int dist;
    if (target == 1) dist = 3;
    else dist = 4;

    while (!pancake.empty()) {
        Node p = pancake.front();
        pancake.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (check[nx][ny]) continue;
            
            check[nx][ny] = true;
            pancake.push({nx, ny, p.dist + 1});

            if (arr[nx][ny] == target) {
                if (dist <= p.dist + 1) continue;
                else {
                    memcpy(check, checkCpy, sizeof(check));
                    return "fail";
                }
            }
        }
    }

    memcpy(check, checkCpy, sizeof(check));
    return "pass";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string sea;
    for (int i = 0; i < 7; i++) {
        cin >> sea;
        for (int j = 0; j < 7; j++) {
            arr[i][j] = sea[j] - '0';
            if (arr[i][j] != 0) check[i][j] = true;
        }
    }
    
    r = sea.length();
    c = sea.length();

    string ans = "";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (check[i][j]) {
                ans = BFS(i, j, arr[i][j]);
                if (ans == "fail") {
                    cout << ans;
                    return 0;
                }
            }
        }
    }

    cout << ans;

    return 0;
}

/*
001
100
020

*/