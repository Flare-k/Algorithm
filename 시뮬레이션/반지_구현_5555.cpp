#include <iostream>
#include <string>
using namespace std;

string target;
int t;
int total = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> target >> t;

    while (t--) {
        string cmp;
        cin >> cmp;

        cmp += cmp;

        if (cmp.find(target) != string::npos) total++; 
    }

    cout << total;

    return 0;
}