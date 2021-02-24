#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
    1 ~ G 개의 게이트
    P개의 비행기가 순서대로 도착할 예정.. i번째 비행기를 1번부터 Gi번째 게이트중 하나에 영구적으로 도킹
    비행기가 어느 게이트에도 도킹할 수 없으면 공항 페쇄 & 이후 어떤 비행기도 도착할 수 X
    가장 많은 비행기를 공항에 도킹시키려 함. 최대 몇 대 도킹?
*/

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    int G, P;
    cin >> G >> P;

    vector<int> v;

    int parking;
    for (int i = 0; i < P; i++) {
        cin >> parking;
        v.push_back(parking);
    }

    bool visit[100001];
    fill(visit, visit + 100001, false);

    int totalDocking = 0;

    for (int i = 0; i < P; i++) {
        int cnt = v[i];

        for (int j = v[i]; j > 0; j--) {
            if (!visit[j]) {
                visit[j] = true;
                totalDocking++;
                break;
            } 
            else {
                cnt--;
            }
        }

        if (cnt == 0) break;
    }

    cout << totalDocking;

    return 0;
}