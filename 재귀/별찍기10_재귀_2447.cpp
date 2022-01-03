#include <iostream>
using namespace std;

void run(int level, int r, int c) {
    if ((r / level) % 3 == 1 && (c / level) % 3 == 1) cout << ' ';
    else {
        if (level / 3 == 0) cout << '*';
        else run(level / 3, r, c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            run(N, i, j);
        }
        cout << '\n';
    }

    return 0;
}