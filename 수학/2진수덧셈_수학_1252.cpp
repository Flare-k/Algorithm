#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<long long> tmp;

    for (int i = 0; i < 2; i++) {
        string bin;
        cin >> bin;

        reverse(bin.begin(), bin.end());
        int len = bin.length();

        int x = 1;
        long long ans = 0;
        int idx = 0;
        while (len--) {
            ans += (x * (bin[idx++] - '0'));
            x *= 2;
        }

        tmp.push_back(ans);
    }

    long long target = 0;
    for (long long num : tmp) {
        target += num;
    }

    if (target == 0) {
        cout << 0;
    }
    else {
        string res = "";
        while (target != 0) {
            res += (target % 2 + '0');
            target /= 2;
        }

        reverse(res.begin(), res.end());
        cout << res;
    }
    

    return 0;
}