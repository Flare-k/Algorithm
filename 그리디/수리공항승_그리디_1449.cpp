#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int pipe[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L; // 물이 새는 곳의 개수, 테이프의 길이
    cin >> N >> L;
    vector<int> hole;

    int v;
    for (int i = 0; i < N; i++) {
        cin >> v;
        hole.push_back(v);
    }

    sort(hole.begin(), hole.end());
    fill(pipe, pipe + 1001, 0);   // 위치 초기화

    int cnt = 0;
    for (int i = 0; i < hole.size(); i++) {
        int tape = hole[i];

        // 만약 테이프가 붙여져 있지 않다면
        if (!pipe[tape]) {
            // 테이프 길이만큼 테이프 붙이기
            for (int j = tape; j < tape + L; j++) {
                    if (j > 1000)
                        break;
                    pipe[j] += 1;
            }
            cnt++;
        }
    }

    cout << cnt;


    return 0;
}