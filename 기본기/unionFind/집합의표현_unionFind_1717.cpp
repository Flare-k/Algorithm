#include <iostream>
#include <vector>
using namespace std;

int n, m, type, a, b;
vector<int> vect(1000002, -1);

int getBoss(int n) {
    if (vect[n] == -1) return n;

    int ret = getBoss(vect[n]);
    vect[n] = ret;

    return ret;
}

void setGroup(int n1, int n2) {
    int g1 = getBoss(n1);
    int g2 = getBoss(n2);

    if (g1 == g2) return;

    vect[g2] = g1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> type >> a >> b;

        if (type == 0) {
            if (getBoss(a) != getBoss(b)) setGroup(b, a);
        }
        else if (type == 1) {
            if (getBoss(a) == getBoss(b)) cout << "YES\n";
            else cout << "NO\n";
        }

    }

    return 0;
}