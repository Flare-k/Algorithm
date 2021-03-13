#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
      개념 체크용으로 배열은 임의로 하드코딩
    */
    int vect[7] {4, 2, 5, 1, 9, 6, 2};
    int res[7] {0, };

    for (int i = 0 ; i < 7; i++) {
        res[i] = vect[i];
        int idx = i;

        while (res[idx - 1] > res[idx]) {
            swap(res[idx - 1], res[idx]);
            idx--;
        }
    }

    for (int i = 0 ; i < 7; i ++) {
        cout << res[i] << ' ';
    }

    return 0;
}