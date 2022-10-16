#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200000
#define LOG 20
using namespace std;
typedef long long ll;
 
struct Node {
    int u, v;
    ll w;
};
 
typedef pair<int, ll> P;
vector<P> list[MAX + 1];
vector<Node> v, nv;
P lcaParent[MAX + 1][LOG];
int mstParent[MAX + 1], depth[MAX + 1];
bool visit[MAX + 1];
ll mst;
int N, M, cnt;
 
bool cmp(Node a, Node b) {
    return a.w < b.w;
}
 
int find(int v) {
    if (mstParent[v] == v) return v;
    return mstParent[v] = find(mstParent[v]);
}
 
void Union(int x, int y, ll w) {
    int a = find(x);
    int b = find(y);
 
    if (a == b) return;
    list[x].push_back({ y, w });
    list[y].push_back({ x, w });
    mstParent[b] = a;
    mst += w;
    cnt++;
}
 
void makeMst() {
    for (int i = 0; i < M; i++) {
        Union(nv[i].u, nv[i].v, nv[i].w);
        if (cnt == N - 1) break;
    }
}
 
void init() {
    for (int i = 1; i <= N; i++) {
        mstParent[i] = i;
    }
}
 
void dfs(int v, int d) {
    depth[v] = d;
    visit[v] = true;
 
    for (int i = 0; i < list[v].size(); i++) {
        int next = list[v][i].first;
        ll w = list[v][i].second;
 
        if (visit[next]) continue;
        lcaParent[next][0] = { v, w };
        dfs(next, d + 1);
    }
}

ll lca(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    ll ret = 0;
 
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i)) {
            ret = max(ret, lcaParent[y][i].second);
            y = lcaParent[y][i].first;
        }
    }
 
    if (x == y) return ret;
 
    for (int i = LOG - 1; i >= 0; i--) {
        if (lcaParent[x][i].first == 0) continue;
        if (lcaParent[x][i].first != lcaParent[y][i].first) {
            ret = max(ret, max(lcaParent[x][i].second, lcaParent[y][i].second));
 
            x = lcaParent[x][i].first;
            y = lcaParent[y][i].first;
        }
    }
 
    return max(ret, max(lcaParent[x][0].second, lcaParent[y][0].second));
}
 
void setParent() {
    dfs(1, 1);
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= N; i++) {
            lcaParent[i][j].first = lcaParent[lcaParent[i][j - 1].first][j - 1].first;
            lcaParent[i][j].second = max(lcaParent[i][j - 1].second, lcaParent[lcaParent[i][j - 1].first][j - 1].second);
        }
    }
 
    for (int i = 0; i < M; i++) {
        ll sub = lca(v[i].u, v[i].v);
        cout << mst - sub + v[i].w << '\n';
    }
}
 
void input() {
    int x, y;
    ll w;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> w;
        v.push_back({ x,y,w });
    }
    nv = v;
    sort(nv.begin(), nv.end(), cmp);
}
 
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
 
    input();
    init();
    makeMst();
    setParent();
 
    return 0;
}