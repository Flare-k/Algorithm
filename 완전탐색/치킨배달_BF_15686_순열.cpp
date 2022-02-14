#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;
const int MAX = 51;
int answer = 21e8;
int map[MAX][MAX];
int cpy[MAX][MAX];

struct Node {
    int x, y;
};

vector<Node> home;
vector<Node> chicken;

int distance(vector<Node> tmp) {
    int sum = 0;
    int hsize = home.size();
    int tsize = tmp.size();

    for (int i = 0; i < hsize; i++) {
        int dist = 1e9;
        int x = home[i].x;
        int y = home[i].y;

        for (int j = 0; j < tsize; j++) {
            int nx = tmp[j].x;
            int ny = tmp[j].y;
            int nd = abs(nx - x) + abs(ny - y);

            dist = min(dist, nd);
        }

        sum += dist;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) home.push_back({i, j});
            if (map[i][j] == 2) chicken.push_back({i, j});
        }
    }

    memcpy(cpy, map, sizeof(cpy));

    int csize = chicken.size();
    vector<int> iter(csize, 0);

    for (int i = 0; i < M; i++) {
        iter[i] = 1;
    }

    sort(iter.begin(), iter.end());

    do {
        vector<Node> tmp;

        for (int i = 0; i < csize; i++) {
            if (iter[i] == 1) {
                Node now = chicken[i];
                tmp.push_back({now.x, now.y});
            }
        }

        answer = min(answer, distance(tmp));

    } while(next_permutation(iter.begin(), iter.end()));

    cout << answer;

    return 0;
}