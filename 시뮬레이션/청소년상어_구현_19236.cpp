#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

// 8->1로 갈수록 반시계 MAX5도
const int MAX = 4;
const int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

// 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸
struct Fish {
    int num, dir;
};

struct Node {
    int x, y;
};

struct Shark {
    int x, y, num, dir;
};

int n, d, result;;

void vectReset(vector<vector<Fish>>& fish, unordered_map<int, Node>& m) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (fish[i][j].num != 0) m[fish[i][j].num] = {i, j};
        }
    }
}

void fishMove(vector<vector<Fish>>& fish, unordered_map<int, Node>& m, Shark& shark, int total) {

    result = max(result, total);

    for (int i = 1; i <= MAX * MAX; i++) {
        if (m.count(i) == true && shark.num != i) {
            
            Node now = m[i];
            int dir = fish[now.x][now.y].dir;
            int flag = 0;

            while (1) {
                if (dir == 9) dir = 1;

                int nx = now.x + dx[dir % 9];
                int ny = now.y + dy[dir % 9];
                
                flag++;
                dir++;

                if (flag > 8) break;

                if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
                if (nx == shark.x && ny == shark.y) continue;

                fish[now.x][now.y].dir = dir - 1;
                
                swap(fish[now.x][now.y], fish[nx][ny]);
                swap(m[fish[now.x][now.y].num], m[fish[nx][ny].num]);

                break;
            }
        }
    }

    m.clear();
    vectReset(fish, m);

    // shark
    int x = shark.x;
    int y = shark.y;
    int dir = shark.dir;

    for (int i = 1; i <= 3; i++) {
        vector<vector<Fish>> tmpFish(MAX, vector<Fish>(MAX));
        tmpFish = fish;
    
        unordered_map<int, Node> tmpM;
        tmpM = m;
        
        
        int nx = x + (dx[dir] * i);
        int ny = y + (dy[dir] * i);

        if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
        if (tmpFish[nx][ny].num == 0) continue;

        shark.x = nx;
        shark.y = ny;

        int eatFish = tmpFish[nx][ny].num;
        shark.num = tmpFish[nx][ny].num;
        tmpFish[nx][ny].num = 0;
        shark.dir = tmpFish[nx][ny].dir;
        tmpFish[nx][ny].dir = 0;

        fishMove(tmpFish, tmpM, shark, total + eatFish);
    }
}

void init(vector<vector<Fish>>& fish, unordered_map<int, Node>& m, Shark& shark) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> n >> d;
        
            if (i == 0 && j == 0) {
                shark = {i, j, n, d};
                fish[i][j] = {0, 0};
                continue;
            }

            fish[i][j] = {n, d};
            m[n] = {i, j};
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unordered_map<int, Node> m;
    vector<vector<Fish>> fish(MAX, vector<Fish>(MAX));
    Shark shark;
    
    init(fish, m, shark);
    fishMove(fish, m, shark, shark.num);

    cout << result;

    return 0;
}