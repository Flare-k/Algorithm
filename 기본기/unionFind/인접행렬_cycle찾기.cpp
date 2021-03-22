#include <iostream>
using namespace std;

/*
  푸는 데 은근 헤맸다...
*/

char vect[100];

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
            if (j > i && matrix) {  // 대각 행렬만 구하면 되므로 j > i 조건을 작성
                if (getBoss('A' + i) == getBoss('A' + j)) {
                    cout << "cycle 발견";
                    return 0;
                }
                
                setGroup('A' + i, 'A' + j);
            }
        }
    }

    cout << "미발견";

    return 0;
}

