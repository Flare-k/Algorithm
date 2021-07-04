#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, m, s;
    cin >> h >> m >> s;

    int sec;
    cin >> sec;
    
    s += sec;
    m += (s / 60);
    h += (m / 60);
    
    cout << h % 24 << ' ' << m % 60 << ' ' << s % 60;

    return 0;
}