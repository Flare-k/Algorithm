#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int H, W, P;  // 층 수, 방 수, 손님 수
        cin >> H >> W >> P;

        // 호수의 층 부분..
        int ho = 0;
        if (P % H != 0)  // 만약 손님수와 층수가 나눠떨어지지 않으면..
            ho += 100 * (P % H);
        else  // 만약 손님수와 층수가 나눠떨어지면 제일 꼭대기 층수에 배정
            ho += 100 * H;

        int cnt = 1;  // 몇번째 객실인지 카운트한다. 제일 첫 객실이 1호이므로 초기값은 1
        while (P - H > 0) {
            P -= H;  // 손님수 - 전체 층수를 거듭하여 빼면 적절한 층수가 나오게 된다.
            cnt++; /* 
                    손님수-층수가 0보다 크면 그 층을 모두 채운것이나 다름없으므로,
                    손님수를 계산하며 호실은 하나씩 증가한다. 
                    */
        }
        ho += cnt; // 층수와 호실을 더해준다.

        cout << ho << endl;
    }

    return 0;
}
