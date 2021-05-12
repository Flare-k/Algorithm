#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
    알고리즘 분류는 그리디이지만 MST(최소신장트리)이기도 하다. 
    MST 방법으로 풀이했다.
*/

int vect[100];

// cost를 기준으로 오름차순 정렬
bool cmp(vector<int>& a, vector<int>& b) {
    if (a[2] < b[2]) return true;
    return false;
}

int getBoss(int node) {
    if (vect[node] == 0) return node;

    int res = getBoss(vect[node]);
    vect[node] = res;
    return res;
}

void setGroup(int c1, int c2) {
    int g1 = getBoss(c1);
    int g2 = getBoss(c2);

    if (g1 == g2) return;
    vect[g2] = g1;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);  // 가중치를 기준으로 오름차순.. 왜? 가장 적은 비용먼저 탐색할거니까(그리디)

    int price = 0;
    int cnt = 0;
    for (int i = 0; i < costs.size(); i++) {
        if (getBoss(costs[i][0]) != getBoss(costs[i][1])) { // 두 노드가 서로 같은 그룹이 아니면 그룹을 지어주자
            cnt++;
            price += costs[i][2];
            setGroup(costs[i][0], costs[i][1]);

            if (cnt == n - 1) break; // 노드가 총 5개이므로 모두 그룹이 맺어질려면 네 번이면 된다.
        }
    }
    
    return price;
}

int main() {
    int ans = solution(4, {{0, 1, 1},
                           {0, 2, 2},
                           {1, 2, 5},
                           {1, 3, 1},
                           {2, 3, 8}});

    return 0;
}