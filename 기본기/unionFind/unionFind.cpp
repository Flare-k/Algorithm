#include <iostream>
using namespace std;

int vect[100];

// getBoss가 리턴되면서 보스를 변경.
/*
그렇게 된다면
a <- b <- c <- d d의 보스가 a임을 확인할 때 계속 재귀를 했어야 했는데
a <- b, a <- b, a <- d 로 더 간결하게 접근이 가능해진다.
*/
char getBoss(char ch) {
    if (vect[ch] == 0) return ch;

    char res = getBoss(vect[ch]);

    vect[ch] = res; // 이 부분을 추가해줌으로써 추후에 getBoss 호출시 이전보다 속도가 더 빠르다. (= 경로 압축)

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