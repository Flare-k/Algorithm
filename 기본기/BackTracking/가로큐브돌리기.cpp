#include <iostream>
using namespace std;

int cube[5][5];
int maxScore = -21e8;
int n;

int score() {
    int total = 1;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += cube[j][i];
        }
        total *= sum;
    }

    return total;
}

void spin(int idx) {
    int temp = cube[idx][n - 1];
    for (int i = n - 1; i >= 1; i--) {
        cube[idx][i] = cube[idx][i - 1];
    }

    cube[idx][0] = temp;
}

void run(int level) {
    if (level == n) {
        if (maxScore < score()) maxScore = score();
        return;
    }

    for (int i = 0; i < n; i++) {
        spin(level);
        run(level + 1);
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cube[i][j];
        }
    }

    run(0);

    cout << maxScore << "점" << '\n';


    return 0;
}