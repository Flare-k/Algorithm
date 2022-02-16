#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 101
using namespace std;

int T;
int vect[MAX];
struct Node {
    int a, b;
};

// bool cmp(Node n, Node m) {
//     if (n.a < m.a) return true;
//     else if (n.a == m.a) {
//         return n.b < m.b;
//     }
//     return false;
// }

// int getBoss(int v) {
//     if (vect[v] == 0) return v;

//     int ret = getBoss(vect[v]);
//     vect[v] = ret;
//     return ret;
// }

// void setGroup(int v1, int v2) {
//     int g1 = getBoss(v1);
//     int g2 = getBoss(v2);

//     if (g1 == g2) return;
//     vect[g2] = g1;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while (T--) {
        int N, M;
        // memset(vect, 0, sizeof(vect));
        // vector<Node> list;

        cin >> N >> M;

        int a, b;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
        }

        cout << N - 1 << '\n';
    }

    return 0;
}