#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        string cmd;
        cin >> cmd;

        cout << cmd.front() << cmd.back() << '\n';
    }

    return 0;
}