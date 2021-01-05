#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iter;
    cin >> iter;
    vector<long long> dist;
    vector<long long> gasStation;

    // 각 거리에 대한 벡터
    for (int i = 0; i < iter - 1; i++) {
        long long a;
        cin >> a;
        dist.push_back(a);
    }

    // 주유소마다 주유비에 대한 벡터
    for (int i = 0; i < iter; i++) {
        long long a;
        cin >> a;
        gasStation.push_back(a);
    }
    
    // 사실상 가장 끝 주유소는 큰 의미가 없어보임
    long long ans = 1000000001;
    long long sum = 0;
    for (int i = 0; i < iter - 1; i++) {
        if (gasStation[i] < ans) {
            ans = gasStation[i];    // 현재 주유소 가격보다 작다면 갱신
        }
        sum += (ans * dist[i]);
    }

    cout << sum;

    return 0;
}
/**
 * 처음에 이중 for-loop로 접근하여 시간초과 오류가 발생했었음..
 * 모든 케이스가 아닌 최적의 케이스만 접근하도록 수정함.
 * */