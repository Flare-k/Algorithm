#include <iostream>
#include <string>

using namespace std;


/**
 * 양쪽 끝사람은 끝에 있는 컵홀더를 쓰면 됨
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string cupHolder;
    cin >> cupHolder;

    // 기본적으로 왼쪽 컵홀더를 쓴다고 가정하자
    int cnt = 0;
    bool firstCouple = true;  // 최초에 LL:커플석이 나오면 두 컵홀더 모두 이용하고 그다음 부턴 모두 오른쪽 컵홀더를 이용하게 된다.
    for (int i = 0; i < cupHolder.length(); i++) {
        if (cupHolder[i] == 'L' && firstCouple) {
            i++;
            cnt++;
            firstCouple = false;  //최초 커플석을 지나면 그 뒤로는 오른쪽 컵홀더를
                            //사용해야 하므로 llCnt는 -1 감소시킨다.
        } 
        else if (cupHolder[i] == 'L') {
            i++;    // 커플석은 LL 두 문자이므로 하나만 읽고 인덱스를 한칸 뛰어넘는다.
        }

        cnt++;  // 기본적으로 모든 좌석에 대한 컵홀더를 1씩 카운트한다.
    }

    cout << cnt;

    return 0;
}