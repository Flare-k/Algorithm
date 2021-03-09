#include <iostream>
#include <string>

using namespace std;

/*
 연속된 네 개의 구간에서 'A'가 가장 많이 등장할 때의 개수를 구하라.
 O(n) 속도로 구현할 것.
*/

/*
 11- 4 까지 for문을 돈다. 처음 0~3에서 A의 개수를 cnt로 카운트하고..
 처음엔 모든 알파벳을 카운트하지만 그 다음부터는 이전 알파벳이 A이면 cnt--하고 다음 알파벳이 A이면 cnt++ 해줘서 
 기존의 A인 경우는 유지하게 한다.
*/

int main() {
    string arr = "RQAABABACTA";

    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[i] == 'A') cnt++;
    }

    int maxCnt = -1;
    for (int i = 0; i <= arr.length() - 4; i++) {
        if (maxCnt < cnt) {
            maxCnt = cnt;
        }
        
        if (i == arr.length() - 4) break;

        if (arr[i] == 'A') cnt--;
        if (arr[i + 4] == 'A') cnt++;
    }

    cout << maxCnt << '\n';

    return 0;
}