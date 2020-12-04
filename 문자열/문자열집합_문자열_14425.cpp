#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> set;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        set.push_back(s);
    }

    sort(set.begin(), set.end());

    int cnt = 0;

    for (int i = 0; i < M; i++) {
        string compS;
        cin >> compS;
        int first = 0;
        int last = N - 1;
        int mid = 0;

        while (first <= last) {
            mid = (first + last) / 2;
            if (compS == set[mid]) {
                cnt++;
                break;
            } 
            else {
                if (compS < set[mid])
                    last = mid - 1;
                else
                   first = mid + 1;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}