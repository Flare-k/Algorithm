#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#define MAX 200010
using namespace std;

int F;
int PR[MAX];
int SC[MAX];
int idx;
unordered_map<string, int> mm;
vector<int> result;

int getRoot(int x) {
    if (PR[x] == x) return x;
    return PR[x] = getRoot(PR[x]);
}

void setGroup(int x, int y) {
    int g1 = getRoot(x);
    int g2 = getRoot(y);
    if (g1 == g2) return;
    PR[g2] = g1;
}

void init(int N) {
    idx = 0;
    mm.clear();
    for (int i = 0; i < MAX; i++) {
        PR[i] = i;
    }
    memset(SC, 0, sizeof(SC));
}

int main() {

    cin >> F;

    while (F--) {
        int N;
        cin >> N;

        init(N);

        while (N--) {
            string A, B;
            cin >> A >> B;
            if (!mm.count(A)) {
                mm[A] = idx++;
                SC[mm[A]] = 1;
            }
            if (!mm.count(B)) {
                mm[B] = idx++;
                SC[mm[B]] = 1;
            }

            int pA = getRoot(mm[A]);
            int pB = getRoot(mm[B]);

            if (pA != pB) {
                int g1 = getRoot(pA);
                int g2 = getRoot(pB);
                PR[g2] = g1;
                SC[g1] += SC[g2];
            }

            pA = getRoot(mm[A]);
            result.push_back(SC[pA]);
        }
    }

    for (int n : result) {
        cout << n << '\n';
    }

    return 0;
}