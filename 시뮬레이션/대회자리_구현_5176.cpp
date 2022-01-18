#include <iostream>
#include <cstring>
using namespace std;

int K, P, M;
int seat[502];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;

    while (K--) {
        memset(seat, 0, sizeof(seat));
        cin >> P >> M;

        int num, cnt = 0;

        for (int i = 1; i <= P; i++) {
            cin >> num;
            if (seat[num] == 0) seat[num] = 1;
            else cnt++;
        }

        cout << cnt << '\n';
    }
    
    return 0;
}