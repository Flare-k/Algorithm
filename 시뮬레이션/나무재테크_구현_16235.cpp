#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;   // M개의 나무를 구매해 땅에 심음
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
const int MAX = 11;
int A[MAX][MAX];    // 추가되는 양분
int map[MAX][MAX];
int dead[MAX][MAX];
vector<int> tree[MAX][MAX];

void spring() {
    memset(dead, 0, sizeof(dead));
    vector<int> tmp;    // 시간단축 포인트

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int size = tree[r][c].size();
            
            if (size > 0) {
                sort(tree[r][c].begin(), tree[r][c].end());
                tmp.clear();
                
                for (int i = 0; i < size; i++) {
                    int age = tree[r][c][i];
                    if (age == 0) continue;

                    if (map[r][c] - age >= 0) {
                        map[r][c] -= age;
                        tmp.push_back(age + 1);    // 시간단축 포인트
                    }
                    else {
                        dead[r][c] += (age / 2);
                    }
                }

                tree[r][c].clear();    // 시간단축 포인트

                for (int t : tmp) {
                    tree[r][c].push_back(t);
                }
            }
        }
    }
}

void summer() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            map[r][c] += dead[r][c];
        }
    }
}

void fall() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int size = tree[r][c].size();
            if (size > 0) {

                for (int i = 0; i < size; i++) {
                    int age = tree[r][c][i];

                    if (age % 5 != 0) continue;

                    for (int j = 0; j < 8; j++) {
                        int nx = r + dx[j];
                        int ny = c + dy[j];

                        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;

                        tree[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            map[r][c] += A[r][c];
        }
    }
}

void init() {
    cin >> N >> M >> K;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> A[r][c];
            map[r][c] = 5;
        }
    }

    int x, y, z;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
}

void result() {
    int answer = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            answer += tree[r][c].size();
        }
    }

    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    init();

    while (K--) {
        spring();
        summer();
        fall();
        winter();
    }

    result();

    return 0;
}