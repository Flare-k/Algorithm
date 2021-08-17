#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, string> um;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    string url, passwd;

    while (N--) {
        cin >> url >> passwd;

        um[url] = passwd;
    }

    while (M--) {
        cin >> url;

        cout << um[url] << '\n';
    }

    return 0;
}