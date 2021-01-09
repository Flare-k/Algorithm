#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;

/**
 * 1. 2칸 위로, 1칸 오른쪽
 * 2. 1칸 위로, 2칸 오른쪽
 * 3. 1칸 아래로, 2칸 오른쪽
 * 4. 2칸 아래로, 1칸 오른쪽
 *
 * 이동 횟수가 네번을 넘으면 모든 이동방법을 한 번씩 사용해야 한다.
 * 네번을 넘지 못하면 이동 방법에 제약이 없다. 즉, 이동 방법에 제약이 없는 경우
 * 최대 이동 칸수는 네 칸이다. (중요)
 *
 *
 * 세로가 1 or 2 or 3이상
 * 세로가 1 → 한 칸밖에 없으므로 1
 * 세로가 2 → 조건 1, 조건 4를 사용하지 못하므로 이동 제약이 없는 경우 최대 이동 칸수는 네칸이다. 
 * 세로가 3 → 가로가 6이하인 경우 최대 이동 칸은 모든 조건을 다 써도 4칸이다.
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    if (N == 1) {
        cout << 1 << endl;
    }
    else if (N == 2) {
        cout << min(4, (M + 1) / 2) << endl;
    }
    else if (N >= 3) {
        if (M <= 6) {
            cout << min(4, M) << endl;
        }
        else {
            cout << M - 2 << endl;
        }
    }

    return 0;
}