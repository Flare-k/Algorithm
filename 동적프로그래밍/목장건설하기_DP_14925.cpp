#include <iostream>
#define MAX 1001
using namespace std;

int map[MAX][MAX];
int arr[MAX][MAX];
int M, N;

int main() {
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    // 목장 초기화
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    int answer = 0;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] = 0;

            if (map[i][j] == 0) {
                int tmp = 21e8;
                tmp = min(tmp, arr[i - 1][j]);  // 현재 좌표의 위
                tmp = min(tmp, arr[i][j - 1]);  // 현재 좌표의 좌측
                tmp = min(tmp, arr[i - 1][j - 1]);  // 현재 좌표의 대각 좌상

                if (tmp == 21e8) tmp = 0;   // 이 중 최소값 + 1을 현재 arr에 갱신해준다.
                arr[i][j] = tmp + 1;

                answer = max(answer, arr[i][j]);    // 사각형의 최대크기
            }
        }
    }

    cout << answer;

    return 0;
}