#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a * b) / gcd(a, b);
}

void reducedFraction(int child, int parent) {
    ll frac = gcd(child, parent);
    child /= frac;
    parent /= frac;

    cout << child << " " << parent;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x1, y1, x2, y2;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    int child, parent;

    if (y1 == y2) {
        child = x1 + x2;
        parent = y1;
    }
    else {
        ll fac = lcm(y1, y2);
        parent = fac;
        child = (x1 * fac / y1) + (x2 * fac / y2);
    }

    reducedFraction(child, parent);

    return 0;
}