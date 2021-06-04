#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> p(N, 0); 

    int cnt = 0;
    int idx = 0;

    while(1) {
        ++p[idx];

        if (p[idx] == M) break;

        if (p[idx] % 2 == 1) {
            idx = (idx + L) % N;
        }
        else {
            idx = (idx - L + N) % N;
        }

        ++cnt;
    }

    cout << cnt;

    return 0;
}