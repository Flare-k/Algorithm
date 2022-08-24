#include <iostream>
#define MAX 102
using namespace std;

int arr[MAX][MAX];
int N, M, A, B;

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;

        arr[A][B] = 1;
        arr[B][A] = -1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][k] == arr[k][j] && arr[i][k] != 0) 
                    arr[i][j] = arr[i][k];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int cnt = N - 1;    // 물건마다 본인은 제외해야 하므로
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] != 0) cnt--;
        }

        cout << cnt << '\n';
    }

    return 0;
}