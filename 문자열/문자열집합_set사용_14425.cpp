#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define SIZE 30
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

set<string> _set;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        _set.insert(word);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        string word;
        cin >> word;
        if (_set.find(word) != _set.end()) cnt++;
    }

    cout << cnt;
}