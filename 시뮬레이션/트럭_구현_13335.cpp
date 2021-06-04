#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int truck, bridgeLen, maxWeight;
    cin >> truck >> bridgeLen >> maxWeight;

    vector<int> trucks(truck);
    for (int i = 0; i < truck; i++) {
        cin >> trucks[i];
    }

    int total = 0;
    int weightSum = 0;
    int time = 0;
    
    queue<int> q;

    for (int i = 0 ; i < trucks.size(); i++) {
        while (1) {
            if (q.size() == bridgeLen) {
                weightSum -= q.front();
                q.pop();
            }

            if (weightSum + trucks[i] <= maxWeight) break;
            q.push(0);
            time++;
        }

        q.push(trucks[i]);
        weightSum += trucks[i];
        time++;
    }

    cout << time + bridgeLen;

    return 0;
}