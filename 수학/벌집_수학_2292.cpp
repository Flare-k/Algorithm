#include <iostream>
using namespace std;

/*
1칸 -> 1 1개
2칸 -> 2~7 6개
3칸 -> 8~19 12개
4칸 -> 20~37 18개

1 (6) 7 (12) 19 (18) 37
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;  // 총 반복 횟수

    long long cnt = 1;
    long long number = 1;
    long long mid = 1;

    while (1) {
        if (number >= n) break;
        mid = 6 * (cnt++);
        number += mid;
    }

    cout << cnt << endl;
    
    return 0;
}
