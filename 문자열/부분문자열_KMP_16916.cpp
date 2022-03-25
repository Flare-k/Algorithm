#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool flag;

vector<int> makeTable(string P) {
    int PSize = P.size();
    vector<int> table(PSize, 0);

    int j = 0;
    for (int i = 1; i < PSize; i++) {
        while (j > 0 && P[i] != P[j]) {
            j = table[j - 1];
        }

        if (P[i] == P[j]) {
            table[i] = ++j;
        }
    }

    return table;
}

void KMP(string S, string P) {
    vector<int> table = makeTable(P);

    int SSize = S.size();
    int PSize = P.size();

    int j = 0;
    
    for (int i = 0; i < SSize; i++) {
        while (j > 0 && S[i] != P[j]) {
            j = table[j - 1];
        }

        if (S[i] == P[j]) {
            if (j == PSize - 1) {
                flag = true;
                return;
                j = table[j];
            }
            else {
                j++;
            }
        }
    }
}

int main() {
    
    string S, P;
    cin >> S >> P;

    KMP(S, P);

    if (flag) cout << 1 << '\n';
    else cout << 0 << '\n';
    
    return 0;
}