#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    cin >> T >> N;

    for (int i = 1; i <= T; i++) {
        string poketmon;
        cin >> poketmon;

        m[poketmon] = to_string(i);
        m[to_string(i)] = poketmon;
    }

    while (N--) {
        string s;
        cin >> s;
        cout << m[s] << '\n';
    }
    
    return 0;
}