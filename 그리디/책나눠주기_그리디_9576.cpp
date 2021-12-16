#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1001;
bool check[MAX];

struct Node {
    int s, e;
};

vector<Node> v;

bool cmp(Node& a, Node& b) {
    if (a.e < b.e) return true;
    else if (a.e == b.e) return a.s < b.s;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        memset(check, false, sizeof(check));
        v.clear();

        int N, M;
        int cnt = 0;

        cin >> N >> M;

        for (int i = 0; i < M; i++) {
            int s, e;
            cin >> s >> e;
            v.push_back({s, e});
        }

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < M; i++) {
            int s = v[i].s;
            int e = v[i].e;

            for (int j = s; j <= e; j++) {
                if (!check[j]) {
                    check[j] = true;
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << '\n';

    }


    return 0;
}
