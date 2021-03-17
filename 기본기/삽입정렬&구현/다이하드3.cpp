#include <iostream>
#include <string>
using namespace std;

int position[7] = {3, 2, -1, 3, -2, 0, -1};

void traceFootprint(int n) {
    if (position[n] == 0) {
        cout << n << "번" << '\n';
        return;
    }

    traceFootprint(n + position[n]);
    cout << n << "번" << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    traceFootprint(n);

    return 0;
}