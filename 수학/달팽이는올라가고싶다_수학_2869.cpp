#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, V;
    cin >> A >> B >> V;

    int res = 0;
    res = (V - B - 1) / (A - B) + 1;

    cout << res;
    
    return 0;
}
/*
달팽이는 하루에 A-B미터씩 총 V미터를 올라가야 한다.
하지만 달팽이가 목표 지점에 도달한 날에는 미끄러지는 것을 감안하면
안 되니 총 V-B미터를 올라가게 되는 것과 같다.
나눠 떨어지는 것을 구분하기 귀찮으므로 V-B-1을 해준다.
미리 -1을 해놓고 몫에 무조건 1을 더하자.
*/