#include <iostream>
#include <cstring>
#include <vector>
#define ll long long
#define matrix vector<vector<ll>>
using namespace std;

const int MAX = 6;
int N;
ll B;

matrix operator * (const matrix& a, const matrix& b) {

    matrix res(N, vector<ll>(N, 0));

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            for (ll k = 0; k < N; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 1000;
        }
    }
    return res;
}

matrix gop(matrix a) {
    matrix res(N, vector<ll>(N));

    for (ll i = 0; i < N; i++) {
        res[i][i] = 1;
    }

    while (B > 0) {
        if (B % 2 == 1) res = res * a;

        B /= 2;
        a = a * a;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> B;

    matrix a(N, vector<ll>(N));

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    
    a = gop(a);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}