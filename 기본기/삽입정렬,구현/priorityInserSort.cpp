#include <iostream>
using namespace std;

struct Prior {
    int num;
    char alpha;
};

int compare(Prior p1, Prior p2) {
    if (p1.num > p2.num) return 1;
    if (p1.num < p2.num) return 0;

    return p1.alpha < p2.alpha;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Prior p[6] {
        {4, 'A'}, {7, 'B'}, {6, 'A'}, {7, 'A'}, {9, 'B'}, {3, 'Q'}
    };

    Prior res[6];

    for (int i = 0; i < 6; i++) {
        int idx = i;

        res[idx] = p[idx];

        for (int j = idx; j > 0; j--) {

            Prior r1 = res[j - 1];
            Prior r2 = res[j];

            if (compare(r1, r2) == 0) {
                swap(res[j - 1], res[j]);
            }
            else {
                break;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        cout << res[i].num << ' ' << res[i].alpha << '\n';
    }

    return 0;
}