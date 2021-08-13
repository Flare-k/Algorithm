#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minn = 21e8;
int maxx = -21e8;
string num;

int checkodd(string s) {
    int cnt = 0;

    for (char ch : s) {
        if ((ch - '0') % 2 == 1) cnt++;
    }

    return cnt;
}

void run(string s, int cnt) {
    if (s.size() == 1) {
        cnt += checkodd(s);
        minn = min(minn, cnt);
        maxx = max(maxx, cnt);
        return;
    }
    else if (s.size() == 2) {
        int s1 = s.front() - '0';
        int s2 = s.back() - '0';

        int ncnt = checkodd(s);
        
        run(to_string(s1 + s2), cnt + ncnt);
    }
    else if (s.size() > 2) {
        vector<bool> btw(s.length() - 1, false);

        for (int i = 0; i < 2; i++) {
            btw[i] = true;
        }

        do {
            vector<int> bdry;
            for (int i = 0; i < s.length() - 1; i++) {
                if (btw[i]) bdry.push_back(i);
            }

            string s1 = s.substr(0, bdry[0] + 1);
            string s2 = s.substr(bdry[0] + 1, bdry[1] - bdry[0]);
            string s3 = s.substr(bdry[1] + 1, s.length() - 1 -bdry[1]);

            string next = to_string(stoi(s1) + stoi(s2) + stoi(s3));
            int ncnt = checkodd(s1) + checkodd(s2) + checkodd(s3);

            run(next, cnt + ncnt);

        } while (prev_permutation(btw.begin(), btw.end()));
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> num;

    run(num, 0);

    cout << minn << ' ' << maxx;

    return 0;
}