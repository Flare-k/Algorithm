#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int pipe[1001];
    
    int N, L;  // 물이 새는 곳의 개수, 테이프의 길이
    cin >> N >> L;
    
    for (int i = 0; i < N; i++) {
        cin >> pipe[i];
    }

    sort(pipe, pipe + N);

    // 범위를 구하기 위해서 기준이되는 기준 지점을 설정한다.
    int pivot = pipe[0];

    int tape = 1;
    for (int i = 1; i < N; i++) {
        // 만약 기준을 넘으면 테이프를 붙이고 현재 지점을 기준으로 다시 삼는다.
        if (pipe[i] - pivot > L - 1) {
            tape++;
            pivot = pipe[i];
        }
    }

    cout << tape;

    return 0;
}