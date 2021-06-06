#include <iostream>
#include <cmath>
using namespace std;

int cnt;
int n, r, c;

void run(int x, int y, int size) {

    if (x == r && y == c) {
        cout << cnt;
        return;
    }

    if (r < x + size && r >= x && c < y + size && c >= y) {
        run(x, y, size / 2);
        run(x, y + size / 2, size / 2);
        run(x + size / 2, y, size / 2);
        run(x + size / 2, y + size / 2, size / 2);
    }
    else {
        cnt += size * size;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> c;

    int size = pow(2, n);

    run(0, 0, size);


    return 0;
}