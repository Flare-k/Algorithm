#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    int currentTime = 0;
    int dist = 0;
    
    for (int i = 0; i < N; i++) {
        int D, R, G;
        cin >> D >> R >> G;

        int period = R + G;

        currentTime += (D - dist);
        dist = D;

        if (currentTime % period <= R) {
            currentTime += (R - currentTime % period);
        }
        else continue;
    }

    currentTime += (L - dist);

    cout << currentTime;

    return 0;
}