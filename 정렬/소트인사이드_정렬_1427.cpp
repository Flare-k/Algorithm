#include <algorithm>
#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    sort(s.rbegin(), s.rend());

    cout << s;
    
    return 0;
}