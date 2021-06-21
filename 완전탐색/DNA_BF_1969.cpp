#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int N, M;
string atgc;
vector<string> dna;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> atgc;
        dna.push_back(atgc);
    }

    string resStr = "";
    int resCnt = 0;

    for (int i = 0; i < M; i++) {
        set<char> setCh;
        map<char, int> mapCh;
        int maxx = 0, idx = 0;

        for (int j = 0; j < N; j++) {
            mapCh[dna[j][i]]++;
            setCh.insert(dna[j][i]);
        }

        for (char c : setCh) {
            if (maxx < mapCh[c]) {
                maxx = mapCh[c];
                idx = c - 'A';
            }
        }

        resCnt += N - maxx;
        resStr += idx + 'A';
    }

    cout << resStr << '\n' << resCnt;

    return 0;
}