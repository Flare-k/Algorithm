#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define ll long long
using namespace std;
struct Node {
    bool s, e;
};
string S, E, Q;
map<string, Node> m;

ll parsing(string str) {
    ll hour = stoll(str.substr(0, 2)) * 100;
    ll minute = stoll(str.substr(3));

    return hour + minute;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> E >> Q;

    ll timeS = parsing(S);
    ll timeE = parsing(E);
    ll timeQ = parsing(Q);

    string str, name;

    while (cin >> str >> name) {
        ll time = parsing(str);

        if (time <= timeS) m[name].s = true;
        else if (time >= timeE && time <= timeQ) m[name].e = true;
    }

    int cnt = 0;

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second.s == true && iter->second.e == true) cnt++;
    }

    cout << cnt << '\n';
   
    return 0;
}