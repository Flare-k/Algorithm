#include <iostream>
using namespace std;

int vect[100];

char getBoss(char ch) {
    if (vect[ch] == 0) return ch;
    char res = getBoss(vect[ch]);
    vect[ch] = res;
    return res;
}

void setGroup(char c1, char c2) {
    char g1 = getBoss(c1);
    char g2 = getBoss(c2);
    if (g1 == g2) return;
    vect[g2] = g1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int matrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix;
            if (j > i && matrix) {
                setGroup('A' + i, 'A' + j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (getBoss('A' + i) == getBoss('A' + j)) {
                cout << "cycle 발견";
                return 0;
            }
        }
    }
    cout << "미발견";

    return 0;
}

