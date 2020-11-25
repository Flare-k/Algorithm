#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int value[1001], inDegree[1001], res[1001];  // 건설 속도 배열, 진입 차수 배열, 결과를 담는 배열
    vector<int> building[1001];  // 건물 벡터
    int N, K, T, W, a, b;
                    // N:건물의 개수, K:순서 규칙의 개수, T:전체 반복 횟수,
                    // W:승리하기 위해 건설해야 할 건물의 번호
                    // a,b:노드 번호
    cin >> T;
    while (T--) {
        cin >> N >> K;
        
        fill(value, value + 1001, 0);
        fill(inDegree, inDegree + 1001, 0);
        fill(res, res + 1001, 0);
        for (int i = 0; i < 1001; i++) {
            building[i].clear();
        }

        for (int i = 1; i <= N; i++) {
            cin >> value[i];
        }   // 건설 속도

        for (int j = 1; j <= K; j++) {
            cin >> a >> b;
            inDegree[b]++;
            building[a].push_back(b);
        }   // 건물 관계

        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if(!inDegree[i]) { 
                q.push(i);
            }
        }

        while (q.size()) {
            int x = q.front();
            q.pop();

            for (int y : building[x]) {
                res[y] = max(res[y], res[x] + value[x]);
                if (--inDegree[y] == 0) {
                    q.push(y);
                }
            }
        }
        cout << res[W] + value[W] << '\n';
        
    }

    return 0;
}
