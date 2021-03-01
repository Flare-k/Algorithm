#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

/*
 통나무를 배치.. 인접한 통나무의 높이 차가 최소가 되어야 한다. -> 서로 골고루 완만하게 배치해야 할 듯
 난이도는 인접한 두 통나무 간의 높이의 차가 최대 값으로 결정된다. -> 배치하고 나서 그중 높이 차가 최대일 때를 구할 것
*/

int main() {
    init();

    int repeat;
    cin >> repeat;

    while (repeat--) {
        int cnt;
        cin >> cnt;
        vector<int> tree(cnt);

        for (int i = 0; i < cnt; i++) {
            cin >> tree[i];
        }

        sort(tree.begin(), tree.end());

        int res = 0;
        for (int i = 2; i < cnt; i++) {
            res = max(res, tree[i] - tree[i - 2]);
        }

        cout << res << '\n';
    }

    return 0;
}