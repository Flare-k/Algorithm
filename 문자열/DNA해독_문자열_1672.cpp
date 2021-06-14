#include <iostream>
#include <string>
using namespace std;

int idx[100];

string dna[4] = {
    "ACAG", 
    "CGTA", 
    "ATCG", 
    "GAGT"
};

void init() {
    idx['A'] = 0;
    idx['G'] = 1;
    idx['C'] = 2;
    idx['T'] = 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int n;
    cin >> n;

    string seq;
    cin >> seq;

    int len = seq.length() - 2;

    while (len >= 0) {
        string tmp = seq.substr(len);

        char r = tmp.front();
        char c = tmp.back();

        char ch = dna[idx[r]][idx[c]];

        seq.pop_back();
        seq.pop_back();

        seq += ch;
        len = seq.length() - 2;
    }

    cout << seq;

    return 0;
}