#include <iostream>
using namespace std;

struct Schedule {
    int day;
    int money;
};

Schedule scd[10];
int used[10];
int maxSum = -21e8;
int n;

void run(int level, int start, int sum) {
    if (level >= n || start == 4) {
        if (maxSum < sum) maxSum = sum;
        return;
    }

    for (int i = start; i < n; i ++) {
        if (used[i] == 1) continue;

        used[i] = 1;
        run(level + scd[i].day, level + scd[i].day, sum + scd[i].money);
        used[i] = 0;
    }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int d, m;
    for (int i = 0; i < n; i++) {
        cin >> scd[i].day >> scd[i].money;
    }

    run(0, 0, 0);

    cout << maxSum;

    return 0;
}
/*

5
3 10
5 20
1 10
1 20
2 15

5
2 20
2 30
1 5
2 10
1 30
*/