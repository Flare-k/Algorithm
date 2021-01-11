#include <iostream>

using namespace std;

/*
 결과적으로 시간복잡도는 O(NM) -> 아무리커도 19x(500^2) -> 5백만보다 작은 수
 */
int a[500][500];

int main() {
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;j++) {
            cin >> a[i][j];
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {   //행
        for (int j = 0; j < m; j++) {//열
            //19가지 도형 변화에 대한 경우의 수를 고려해줘야한다.
            if (j + 3 < m) { //1
                int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
                if (ans < temp) ans = temp;
            }
            if (i+3 < n) { //2
                int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
                if (ans < temp) ans = temp;
            }
            if (i + 1 < n && j + 2 < m) { //3
                int temp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
                if (ans < temp) ans = temp;
            }
            if (i + 2 < n && j + 1 < m) { //4
                int temp = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 2][j];
                if (ans < temp) ans = temp;
            }
            if (i + 1 < n && j + 2 < m) { //5
                int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2];
                if (ans < temp) ans = temp;
            }
            if (i + 2 < n && j - 1 >= 0) { //6
                int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j - 1];
                if (ans < temp) ans = temp;
            }
            if (i - 1 >= 0 && j + 2 < m) { //7
                int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 2];
                if (ans < temp) ans = temp;
            }
            if (i + 2 < n && j + 1 < m) { //8
                int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1];
                if (ans < temp) ans = temp;
            }
            if (i + 1 < n && j + 2 < m) { //9
                int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j];
                if (ans < temp) ans = temp;
            }
            if (i + 2 < n && j + 1 < m) { //10
                int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
                if (ans < temp) ans = temp;
            }
            if (i + 1 < n && j + 1 < m) { //11
                int temp = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
                if (ans < temp) ans = temp;
            }
            if (i - 1 >= 0 && j + 2 < m) { //12
                int temp = a[i][j] + a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j + 2];
                if (ans < temp) ans = temp;
            }
            if (i + 2 < n && j + 1 < m) { //13
                int temp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1];
                if (ans < temp) ans = temp;
            }
            if (i + 1 < n && j + 2 < m) { //14
                int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
                if (ans < temp) ans = temp;
            }
            if (i + 2 < n && j - 1 >= 0) { //15
                int temp = a[i][j] + a[i + 1][j] + a[i + 1][j - 1] + a[i + 2][j - 1];
                if (ans < temp) ans = temp;
            }
            if (j + 2 < m) { //16
                int temp = a[i][j] + a[i][j + 1] + a[i][j + 2];
                if (i - 1 >= 0) {
                    int temp2 = temp + a[i - 1][j + 1];
                    if(ans < temp2) ans = temp2;
                }
                if (i + 1 < n) {
                    int temp2 = temp + a[i + 1][j + 1];
                    if (ans < temp2) ans = temp2;
                }
            }
            if (i + 2 < n) { //17
                int temp = a[i][j] + a[i + 1][j] + a[i + 2][j];
                if (j + 1 < m) {
                    int temp2 = temp + a[i + 1][j + 1];

                    if(ans < temp2) ans = temp2;
                }
                if (j - 1 >= 0) {
                    int temp2 = temp + a[i+1][j-1];
                    if(ans < temp2) ans = temp2;
                }
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
