#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int costp = 21e8;
int costi = 21e8;
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int package, individual;

    for (int i = 0; i < M; i++) {
        cin >> package >> individual;
        costp = min(costp, package);
        costi = min(costi, individual);
    }

    int A = (N / 6 + 1) * costp;
    int B = (N / 6 * costp) + (N % 6 * costi);
    int C = N * costi;

    cout << min(A, min(B, C));

    return 0;
}