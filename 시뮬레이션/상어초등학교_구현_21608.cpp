#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 21;
const int MMAX = 21 * 21;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N;

vector<int> students[MMAX];
vector<int> studentsList;
int arr[MAX][MAX];
bool adjacent[MMAX];

struct Node {
    int x, y, adjacent, empty;
};

bool cmp(Node a, Node b) {
    if (a.adjacent > b.adjacent) return true;
    else if (a.adjacent == b.adjacent) {
        if (a.empty > b.empty) return true;
        else if (a.empty == b.empty) {
            if (a.x < b.x) return true;
            else if (a.x == b.x) return a.y < b.y;
        }
    }

    return false;
}

vector<Node> position;

/*
1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
*/
void run() {
    for (int student : studentsList) {
        position.clear();
        memset(adjacent, false, sizeof(adjacent));

        for (int i = 0; i < 4; i++) {
            adjacent[students[student][i]] = true;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int cnt = 0;
                int ncnt = 0;
                if (arr[i][j] != 0) continue;

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 1 || ny < 1 || nx > N || ny > N) continue;

                    if (adjacent[arr[nx][ny]] == true) cnt++;
                    if (arr[nx][ny] == 0) ncnt++;
                }

                position.push_back({i, j, cnt, ncnt});
            }
        }

        sort(position.begin(), position.end(), cmp);
        Node v = position.front();
        arr[v.x][v.y] = student;
    }
}

// 만족도
int satisfaction() {
    int answer = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cnt = 0;
            memset(adjacent, false, sizeof(adjacent));
            int v = arr[i][j];

            for (int k = 0; k < 4; k++) {
                adjacent[students[v][k]] = true;
            }

            for (int z = 0; z < 4; z++) {
                int nx = i + dx[z];
                int ny = j + dy[z];

                if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
                if (adjacent[arr[nx][ny]] == true) cnt++;
            }

            if (cnt == 1) answer += 1;
            else if (cnt == 2) answer += 10;
            else if (cnt == 3) answer += 100;
            else if (cnt == 4) answer += 1000;
        }   
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int a, b;
    for (int i = 0; i < N*N; i++) {
        cin >> a;
        studentsList.push_back(a);
        for (int j = 0; j < 4; j++) {
            cin >> b;
            students[a].push_back(b);
        }
    }

    run();

    cout << satisfaction();

    return 0;
}