#include <iostream>
#include <utility>
#define INF 987654321
using namespace std;

void floydWarshall(int arr[][4], int n){
    int d[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            d[i][j] = arr[i][j];
        }
    }

    // k = 거쳐가는 노드
    for (int k = 0; k < n; k++){
        // i = 출발 노드
        for (int i = 0; i < n; i++) {
            // j = 도착 노드
            for (int j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
       // j = 도착 노드
        for (int j = 0; j < n; j++) {
            cout << d[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a[4][4] = {
                    {0, 5, INF, 8}, 
                    {7, 0, 9, INF}, 
                    {2, INF, 0, 4}, 
                    {INF, INF, 3, 0}
                };
    floydWarshall(a, 4);

   return 0;
}