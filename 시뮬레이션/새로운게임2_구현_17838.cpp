#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
int N, K;
const int MAX = 13;
// bool check[MAX][MAX][MAX];  // check[i][j][k] i,j에 k번째 (이동한다면 자기 자신 포함 k+1이후에서 true인 값들 같이 들고가기)
// int seq[MAX][MAX];  // 체스의 각 위치에서 몇번째 말까지 있는지 저장 (다음 말을 업는 경우를 위해)
int chess[MAX][MAX];    // 흰색, 빨간색, 파란색 확인만..
struct Node {
    int i, j, num, dir;
};
map<int, Node> cur; // 현재 말의 위치
vector<vector<vector<Node>>> horse;

enum {
    UP, DOWN, LEFT, RIGHT
};

// 말의 이동 매커니즘
void run() {
    int horse = 1;

    while (1) {

        

        if (horse == K) horse = 0;
        horse++;
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> chess[i][j];
        }
    }

    horse.resize(N, vector<vector<Node>>(N));
    int idx = 1;
    for (int i = 0; i < K; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        horse[x - 1][y - 1].push_back({x - 1, y - 1, idx, dir - 1});
        cur[idx] = {x - 1, y - 1, idx, dir - 1};
        idx+;
    }

    return 0;
}