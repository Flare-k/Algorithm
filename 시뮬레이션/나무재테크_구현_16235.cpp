#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
using namespace std;

int N, M, K;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
const int MAX = 11;
int arr[MAX][MAX];
int A[MAX][MAX];

vector<int> tree[MAX][MAX];

/*
봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. = 나무의 나이만큼 A[x][y]에서 빼기, 나무 나이 + 1
하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. = tree[x][y]엔 하나의 나무만 있는게 아님

여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.

가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
*/

void winter() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] += A[i][j];
        }
    }
}

void run() {
    vector<int> tmp;

    while (K--) {
        // Spring and Summer
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (tree[i][j].size() > 0) {
                    int deadtree = 0;
                    tmp.clear();

                    sort(tree[i][j].begin(), tree[i][j].end());
                    for (int k = 0; k < tree[i][j].size(); k++) {
                        int year = tree[i][j][k];

                        if (arr[i][j] >= year) {
                            arr[i][j] -= year;
                            tmp.push_back(year + 1);
                        } 
                        else {
                            deadtree += (year / 2);
                        }
                    }

                    tree[i][j].clear();

                    for (int k = 0; k < tmp.size(); k++) {
                        tree[i][j].push_back(tmp[k]);
                    }

                    arr[i][j] += deadtree;
                }
            }
        }

        // fall
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < tree[i][j].size(); k++) {
                        int year = tree[i][j][k];

                        if (year % 5 != 0) continue;

                        for (int idx = 0; idx < 8; idx++) {
                            int nx = i + dx[idx];
                            int ny = j + dy[idx];

                            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                            tree[nx][ny].push_back(1);
                        }
                    }
            }
        }

        // winter
        winter();
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            arr[i][j] = 5;
        }
    }

    int x, y, year;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> year;
        tree[x - 1][y - 1].push_back(year);
    }

    run();

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer += tree[i][j].size();
        }
    }

    cout << answer;

    return 0;
}