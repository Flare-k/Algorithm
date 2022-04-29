#include <iostream>
#include <algorithm>
#define MAX 12
using namespace std;

int N, maxx, minn;
int A[MAX];

void run(int result, int plus, int minus, int mult, int div, int idx) {
    if (plus < 0 || minus < 0 || mult < 0 || div < 0) return;
    if (N < idx) {
        maxx = max(maxx, result);
        minn = min(minn, result);
        return;
    }
    
    run(result + A[idx], plus - 1, minus, mult, div, idx + 1);
    run(result - A[idx], plus, minus - 1, mult, div, idx + 1);
    run(result * A[idx], plus, minus, mult - 1, div, idx + 1);
    int num = result > 0 ? -(-result / A[idx]) : result / A[idx];
    run(num, plus, minus, mult, div - 1, idx + 1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int p, s, m, d;
    cin >> p >> s >> m >> d;

    maxx = -21e8;
    minn = 21e8;
    
    run(A[1], p, s, m, d, 2);
    
    cout << maxx << '\n';
    cout << minn << '\n';

    return 0;
}
