#include <iostream>
#include <string>
using namespace std;

// level 3, branch 4
/*
 순열이든 조합이든 중복을 제거해야 하면 used 배열을 사용하고 
 그렇지 않으면 start 파라미터 차이
 순열은 start 파라미터가 필요 없고, 조합은 필요하다.
*/

char path[10];

// n개의 재료 중 3개를 선택해야 한다.
// 같은 재료 넣어도 될 때, 총 가능한 모든 조합을 모두 출력할 것.


void run(int level, int start, string target) {

    if (level == 3) {
        cout << path << '\n';
        return;
    }

    for (int i = start; i < target.length(); i++) {
        path[level] = target[i];
        run(level + 1, i, target);
        path[level] = 0;
    }

}

int main() {
    string gimbap;
    cin >> gimbap;

    run(0, 0, gimbap);

    return 0;
}