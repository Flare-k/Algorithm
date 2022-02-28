#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#define MAX 11
using namespace std;

const int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
int N, M, K;
char board[MAX][MAX];
vector<string> vect;
map<string, int> m;
string target;

void run(int x, int y) {
    if (target.length() > 5) return;

    auto iter = m.find(target);
    if (iter != m.end()) {
        iter->second++;
    }

    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx > N) nx = 1;
        else if (nx < 1) nx = N;
        
        if (ny > M) ny = 1;
        else if (ny < 1) ny = M;

        target += board[nx][ny];
        run(nx, ny);
        target.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        string path;
        cin >> path;
        m[path] = 0;
        vect.push_back(path);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            target += board[i][j];
            run(i, j);
            target = "";
        }
    }

    for (string v : vect) {
        cout << m[v] << '\n';
    }

    return 0;
}