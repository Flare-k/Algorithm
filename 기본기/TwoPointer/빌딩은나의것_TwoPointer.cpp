#include <iostream>
using namespace std;

 /*
    최대 수익이 되는 빌딩의 startIndex와 endIndex를 구하라.

    Ex,
    14
    1 2 3 2 -3 0 1 -8 3 2 3 -1 2 -3

    Output: 8 12
    */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;   // 빌딩의 수

    int building[n];    // 빌딩당 수익

    for (int i = 0; i < n; i++) {
        cin >> building[i];
    }


    int startIdx = 0;

    int maxPrice = -1;
    int sum = 0;

    int maxStart = 0;
    int maxEnd = 0;

    for (int i = 0; i < n; i++) {
        sum += building[i];

        if (sum < 0) {
            sum = 0;
            startIdx = i + 1;
        }
        else {
            if (maxPrice < sum) {
                maxPrice = sum;
                maxStart = startIdx;
                maxEnd = i;
            }
        }

    }

    cout << maxStart << " " << maxEnd;

    return 0;
}