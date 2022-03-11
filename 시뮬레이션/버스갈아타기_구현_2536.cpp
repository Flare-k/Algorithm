#include <iostream>
#include<cstring>
#include<queue>
#include<vector>
#define MAX 100001
using namespace std;

int n, m, k;
int sx, sy, ex, ey;
struct Node {
    int x1, y1, x2, y2;
};
struct Dir {
    int s, e, num;
};
Node bus[MAX];
vector<Dir> hzt[MAX]; // 수평
vector<Dir> vtc[MAX]; // 수직
int visit[MAX];
int answer;

void run() {
    queue<int> q;

    // (sx, sy) 에서 시작할 수 있는 경로의 가지
    for (Dir v : vtc[sx]) {
        if (v.s <= sy && sy <= v.e) {
            visit[v.num] = 1;
            q.push(v.num);
        }
    }

    for (Dir h : hzt[sy]) {
        if (h.s <= sx && sx <= h.e) {
            visit[h.num] = 1;
            q.push(h.num);
        }
    }

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        int x1 = bus[num].x1, y1 = bus[num].y1;
        int x2 = bus[num].x2, y2 = bus[num].y2;

        if (y1 == y2) {
            // 특정 번호의 버스 경로에서 수직으로 가는 경우
            if (y1 == ey && ex >= x1 && ex <= x2) {
                cout << visit[num] << '\n';
                return;
            }

            for (int x = x1; x <= x2; x++) {
                for (Dir v : vtc[x]) {
                    if (!visit[v.num] && (v.s <= y1 && y1 <= v.e)) {
                        visit[v.num] = visit[num] + 1;
                        q.push(v.num);
                    }
                }
            }
            // 같은 범위 내에서 갈아탈 수 있는 수평 (겹치는 경우)
            for (Dir h : hzt[y1]) {
                if (!visit[h.num] && !(x1 > h.e || x2 < h.s)) {
                    visit[h.num] = visit[num] + 1;
                    q.push(h.num);
                }
            }
        }
        else if (x1 == x2) {
            // 특정 번호의 버스 경로에서 수평으로 가는 경우
            if (x1 == ex && ey >= y1 && ey <= y2) {
                cout << visit[num] << '\n';
                return;
            }

            for (int y = y1; y <= y2; y++) {
                for (Dir h : hzt[y]) {
                    if (!visit[h.num] && (x1 >= h.s && x1 <= h.e)) {
                        visit[h.num] = visit[num] + 1;
                        q.push(h.num);
                    }
                }
            }
            
            for (Dir v : vtc[x1]) {
                if (!visit[v.num] && !(y1 > v.e || y2 < v.s)) {
                    visit[v.num] = visit[num] + 1;
                    q.push(v.num);
                }
            }
        }
    }

}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        int b, x1, y1, x2, y2;
        cin >> b >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        bus[b] = {x1, y1, x2, y2};

        if (x1 == x2) vtc[x1].push_back({y1, y2, b});  // 수직
        if (y1 == y2) hzt[y1].push_back({x1, x2, b});  // 수평
    }

    cin >> sx >> sy >> ex >> ey;

    run();

    return 0;
}