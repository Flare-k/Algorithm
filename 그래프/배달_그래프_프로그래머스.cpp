#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int next, time;
};

vector<Node> vect[51] = {};
int visit[52][52] = { 0 };

void DFS(int idx, int sum, int N, int K) {

    for (int i = 0; i < vect[idx].size(); i++) {
        int next = vect[idx][i].next;
        int time = vect[idx][i].time;

        if (sum + time > K) continue;
        if (visit[idx][next] != 0 && visit[idx][next] <= sum + time) continue;

        visit[next][0] = 1; // 방문체크
        visit[idx][next] = sum + time;  // 누적 시간 갱신
        DFS(next, sum + time, N, K);
    }
}

int solution(int N, vector<vector<int>> road, int K) {

    for (int i = 0; i < road.size(); i++) {
        int from = road[i][0];
        int to = road[i][1];
        int time = road[i][2];

        vect[from].push_back({to, time});
        vect[to].push_back({from, time});
    }

    visit[1][0] = 1;
    DFS(1, 0, N, K);

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (visit[i][0] == 1) answer++;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> road = {{1, 2, 1},
                                {2, 3, 3},
                                {5, 2, 2},
                                {1, 4, 2},
                                {5, 3, 1},
                                {5, 4, 2}};

    cout << solution(5, road, 3) << '\n';

    return 0;
}

