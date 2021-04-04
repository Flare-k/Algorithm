#include <iostream>
using namespace std;

struct Schedule {
    int day;
    int money;
};

Schedule scd[10];

int maxSum = -21e8;
int n;

void run(int start, int sum) {
    if (maxSum >= sum) return;

    if (start >= n) {
        if (maxSum < sum) maxSum = sum;
        return;
    }

    for (int i = start; i < n; i ++) {
        run(i + scd[i].day, sum + scd[i].money);
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

    run(0, 0);

    cout << maxSum << '\n';;
  
    return 0;
}
/*

5
3 10
5 20
1 10
1 20
2 15
> 45

5
2 20
2 30
1 5
2 10
1 30
> 60
*/