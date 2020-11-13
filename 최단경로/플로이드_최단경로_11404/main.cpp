#include <iostream>
#include <algorithm>
#define endl "\n"
#define INF 1e9

using namespace std;

/*
Key Point: "시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다."
*/

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int busStop[101][101];
   int n, m;
   cin >> n >> m;

    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= n; j++) {
            if (i == j)
                busStop[i][j] = 0;
            else
                busStop[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        if(busStop[a][b] > c)
            busStop[a][b] = c;
    }

    for(int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                busStop[i][j] = min(busStop[i][j], busStop[i][k] + busStop[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            if (busStop[i][j] == INF){
                cout << 0 << " ";
            } 
            else{
               cout << busStop[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
