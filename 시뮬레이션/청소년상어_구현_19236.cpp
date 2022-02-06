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

void vectReset(vector<vector<Fish>>& map, unordered_map<int, Node>& fish) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (map[i][j].num != 0) fish[map[i][j].num] = {i, j};
        }
    }
}

void fishMove(vector<vector<Fish>>& map, unordered_map<int, Node>& fish, Shark& shark, int total) {

    result = max(result, total);

    for (int i = 1; i <= MAX * MAX; i++) {
        if (fish.count(i) == true && shark.num != i) {
            
            Node now = fish[i];
            int dir = map[now.x][now.y].dir;
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

                map[now.x][now.y].dir = dir - 1;
                
                swap(map[now.x][now.y], map[nx][ny]);
                swap(fish[map[now.x][now.y].num], fish[map[nx][ny].num]);

                break;
            }
        }
    }

    fish.clear();
    vectReset(map, fish);

    // shark
    int x = shark.x;
    int y = shark.y;
    int dir = shark.dir;

    for (int i = 1; i <= 3; i++) {
        vector<vector<Fish>> tmp = map;
        unordered_map<int, Node> tmpFish = fish;
        
        int nx = x + (dx[dir] * i);
        int ny = y + (dy[dir] * i);

        if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
        if (tmp[nx][ny].num == 0) continue;

        int eatFish = tmp[nx][ny].num;
        
        shark = {nx, ny, tmp[nx][ny].num, tmp[nx][ny].dir};
        tmp[nx][ny] = {0, 0};

        fishMove(tmp, tmpFish, shark, total + eatFish);
    }
}

void init(vector<vector<Fish>>& map, unordered_map<int, Node>& fish, Shark& shark) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> n >> d;
        
            if (i == 0 && j == 0) {
                shark = {i, j, n, d};
                map[i][j] = {0, 0};
                continue;
            }

            map[i][j] = {n, d};
            fish[n] = {i, j};
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unordered_map<int, Node> fish;
    vector<vector<Fish>> map(MAX, vector<Fish>(MAX));
    Shark shark;
    
    init(map, fish, shark);
    fishMove(map, fish, shark, shark.num);

    cout << result;

    return 0;
}