#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, target;
    cin >> n >> target; // 크기, 찾고자 하는 수

    int arr[n][n];
    memset(arr, 0, sizeof(arr));

    int r = n / 2;
    int c = n / 2;

    int idx = 1;
    int value = 1;
    arr[r][c] = value++;

    while (1) {
        for (int i = 0; i < idx; i++){
            arr[--r][c] = value++;
        }

        if (arr[0][0] != 0) break;

        for (int i = 0; i < idx; i++){
            arr[r][++c] = value++;
        }

        idx++;

        for (int i = 0; i < idx; i++){
            arr[++r][c] = value++;
        }

        for (int i = 0; i < idx; i++){
            arr[r][--c] = value++;
        }

        idx++;
    }

    int nx, ny;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
            
            if (arr[i][j] == target) {
                nx = i + 1;
                ny = j + 1;
            }
        }
        cout << '\n';
    }

    cout << nx << ' ' << ny;

    return 0;
}