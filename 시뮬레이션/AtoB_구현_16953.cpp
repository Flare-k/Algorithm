#include <iostream>
#include <vector>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

/*
A를 B로 바꾸려한다. 
1. 2를 곱한다
2. 1을 수의 가장 오른쪽에 추가한다.
A를 B로 바꾸는데 필요한 연산의 최솟값 구하기

다른 분들 블로그 봤을 때, 이 방법말고 queue를 이용해서 x2, x10 + 1 한 값들을 모조리 다 넣는 케이스도 있었다.
*/
long long ans = 0;

void aToB(long long A, long long B, long long cnt) {
    if (A == B) {
        ans = cnt + 1;
        return;
    }

    if (A < B) {
        cnt += 1;
        aToB(A * 2, B, cnt);
        aToB((A * 10) + 1, B, cnt);
    }
}

int main() {
    init();

    long long A, B;
    cin >> A >> B;

    long long cnt = 0;

    aToB(A, B, cnt);

    if (ans != 0){
        cout << ans;
    }
    else {
        cout << -1;
    }
    
    return 0;
}