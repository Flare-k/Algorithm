#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 5
using namespace std;

struct Node {
    int num;
    char type;
};

Node element[10][4][4][4];
bool used[11];
int N, answer;

int getAnswer(vector<vector<Node>> arr) {
    int R = 0, B = 0, G = 0, Y = 0;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (arr[i][j].type == 'R') R += arr[i][j].num;
            else if (arr[i][j].type == 'B') B += arr[i][j].num;
            else if (arr[i][j].type == 'G') G += arr[i][j].num;
            else if (arr[i][j].type == 'Y') Y += arr[i][j].num;
        }
    }

    return (7 * R) + (5 * B) + (3 * G) + (2 * Y);
}

vector<vector<Node>> changeState(vector<vector<Node>> arr, int r, int c, int idx, int dir) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            arr[r + i][c + j].num += element[idx][dir][i][j].num;

            if (arr[r + i][c + j].num < 0) arr[r + i][c + j].num = 0;
            else if (arr[r + i][c + j].num > 9) arr[r + i][c + j].num = 9;

            if (element[idx][dir][i][j].type != 'W') arr[r + i][c + j].type = element[idx][dir][i][j].type;
        }
    }

    return arr;
}

void clockwise(int idx, int dir) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            element[idx][dir][j][3 - i] = element[idx][dir - 1][i][j];
        }
    }
}

void run(vector<vector<Node>> arr, int level) {
    if (level == 3) {
        answer = max(answer, getAnswer(arr));
        return;
    }

    for (int idx = 0; idx < N; idx++) {
        if (used[idx]) continue;

        used[idx] = true;
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int d = 0; d < 4; d++) {
                    vector<vector<Node>> tmp = changeState(arr, i, j, idx, d);

                    run(tmp, level + 1);
                }
            }
        }

        used[idx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int iter = N;
    int idx = 0;

    while (iter--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> element[idx][0][i][j].num;
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> element[idx][0][i][j].type;
            }
        }

        // 시계방향으로 돌렸을때의 경우도 모두 저장
        for (int dir = 1; dir <= 3; dir++) {
            clockwise(idx, dir);
        }

        idx++;
    }

    vector<vector<Node>> arr(MAX, vector<Node>(MAX));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            arr[i][j] = {0, 'W'};
        }
    }

    run(arr, 0);

    cout << answer << '\n';

    return 0;
}

