#include <iostream>
#include <cstring>
using namespace std;
/*
  마리오는 2, 3, 5칸 중에 하나를 선택해서 점프할 수 있다.
  점프해서 닿을 때마다 점수를 얻을 수 있는데 도착지점까지 갔을 떄 얻을 수 있는 최대 점수는?
  경로까지 출력할 것.
*/
int vec[30] = {1, 3, -1, 6, -3, -1, 5, 100, 3, 2, 5, 1};
int jump[3] = {2, 3, 5};
int maxPath[12];
int path[12];
int maxSum = -21e8;

void run(int level, int now, int sum) {
    if (now >= 12) {
        if (maxSum < sum) {
            maxSum = sum;
            memcpy(maxPath, path, 4 * 12);  // for문으로 copy하는 것보다 훨씬 빠르다. | cstring
        }
        return;
    }

    for (int i = 0; i < 3; i++) {
        int nextNow = now + jump[i];

        path[level] = nextNow;
        run(level + 1, nextNow, sum + vec[nextNow]);
        path[level] = 0;
    }
}

int main() {

    run(0, 0, vec[0]);
    cout << "max: " << maxSum << '\n';

    for (int i = 0; i < 12; i++) {
        if (maxPath[i]) {
            cout << maxPath[i] << ' ';
        }
    }

    return 0;
}