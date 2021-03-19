#include <iostream>
#include <set>
using namespace std;

/* 총 몇 개의 그룹으로 이루어져 있을까? */
/*
 a <- e
 f <- e
 c <- e
 c <- a
 b <- d
 d <- b
 */

int vect[200];

// find
char getBoss(char ch) {
    if (vect[ch] == 0) return ch;

    char res = getBoss(vect[ch]);
    vect[ch] = res;
    return res;
}

// union
void setGroup(char c1, char c2) {
    char g1 = getBoss(c1);
    char g2 = getBoss(c2);

    if (g1 == g2) return;
    vect[g2] = g1;
}

int main() {
    // 방법 1.
    char list[6][3] = 
    {
        "ae",
        "fe",
        "ce",
        "ca",
        "bd",
        "db"
    };

    int cnt = 6;
    for (int i = 0; i < 6; i++) {
        if (getBoss(list[i][0]) != getBoss(list[i][1])) {
            setGroup(list[i][0], list[i][1]);
            cnt--;
        }
    }

    cout << "방법 1 : " << cnt << "\n";


    // 방법 2.
    // union
    setGroup('a', 'e');
    setGroup('f', 'e');
    setGroup('c', 'e');
    setGroup('c', 'a');
    setGroup('b', 'd');
    setGroup('d', 'b');

    set<char> s;
    for (int i = 0; i < 6; i++) {
        s.insert(getBoss('a' + i));
    }

    cout << "방법 2 : " << s.size() << "\n";

    return 0;
}