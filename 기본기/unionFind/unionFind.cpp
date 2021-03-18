#include <iostream>
using namespace std;

int vect[100];

char getBoss(char ch) {
    if (vect[ch] == 0) return ch;
    char res = getBoss(vect[ch]);

    return res;
}

void setGroup(char t1, char t2) {
    char g1 = getBoss(t1);
    char g2 = getBoss(t2);

    if (g1 == g2) return;
    vect[g2] = g1;
}

int main() {

    // union
    setGroup('C', 'D');
    setGroup('B', 'C');
    setGroup('A', 'B');

    cout << getBoss('D') << '\n';

    // find
    if (getBoss('A') == getBoss('B')) {
        cout << "같은 그룹이다.";
    }
    else {
        cout << "다른 그룹이다.";
    }

    return 0;
}