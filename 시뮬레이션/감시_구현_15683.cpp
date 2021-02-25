#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>

using namespace std;

int r, c;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void check(vector<vector<int>>& office, vector<vector<int>>& tmp, int x, int y, int dir) {
    int nx = x;
    int ny = y;

    while (0 <= nx && nx < r && 0 <= ny && ny < c) {
        if (tmp[nx][ny] == 6) break;

        tmp[nx][ny] = office[x][y];

        nx += dx[dir];
        ny += dy[dir];
    }
}

int answer(vector<vector<int>>& office, vector<tuple<int, int, int>>& cctv, int idx, vector<int> dirs) {

    if (cctv.size() == idx) {
        vector<vector<int>> tmp(office);

        for (int i = 0; i < cctv.size(); i++) {
            int cctvNum, x, y;
            tie(cctvNum, x, y) = cctv[i];

            if (cctvNum == 1) {
                check(office, tmp, x, y, dirs[i]);
            } 
            else if (cctvNum == 2) {
                check(office, tmp, x, y, dirs[i]);
                check(office, tmp, x, y, (dirs[i] + 2) % 4);
            } 
            else if (cctvNum == 3) {
               check(office, tmp, x, y, dirs[i]);
               check(office, tmp, x, y, (dirs[i] + 1) % 4);
            } 
            else if (cctvNum == 4) {
                check(office, tmp, x, y, dirs[i]);
                check(office, tmp, x, y, (dirs[i] + 1) % 4);
                check(office, tmp, x, y, (dirs[i] + 2) % 4);
            } 
            else if (cctvNum == 5) {
                check(office, tmp, x, y, dirs[i]);
                check(office, tmp, x, y, (dirs[i] + 1) % 4);
                check(office, tmp, x, y, (dirs[i] + 2) % 4);
                check(office, tmp, x, y, (dirs[i] + 3) % 4);
            }
        }

        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (tmp[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }
    
    int ans = 100;

    for (int i = 0; i < 4; i++) {
        dirs[idx] = i;

        int temp = answer(office, cctv, idx + 1, dirs);

        ans = min(ans, temp);
    }

    return ans;
}

int main() {
    init();

    cin >> r >> c;

    vector<vector<int>> office(r, vector<int>(c));
    vector<tuple<int, int, int>> cctv;
    vector<int> dirs;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> office[i][j];

            if (1 <= office[i][j] && office[i][j] <= 5) {
                cctv.emplace_back(office[i][j], i, j);
                dirs.push_back(0);
            }
        }
    }

    cout << answer(office, cctv, 0, dirs);

    return 0;
}