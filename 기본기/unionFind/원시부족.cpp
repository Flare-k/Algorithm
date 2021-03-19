#include <iostream>
#include <string>
using namespace std;

int check[200];

char getBoss(char ch) {
    if (check[ch] == 0) return ch;

    char ret = getBoss(check[ch]);
    check[ch] = ret;

    return ret;
}

void setGroup(char c1, char c2, int& cnt) {
    char g1 = getBoss(c1);
    char g2 = getBoss(c2);

    if (g1 == g2) return;
    check[g2] = g1;

    cnt--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 10;

    // 그룹지어주기
    setGroup('A', 'B', cnt);
    setGroup('A', 'C', cnt);
    setGroup('E', 'D', cnt);
    setGroup('E', 'F', cnt);
    setGroup('I', 'J', cnt);
    setGroup('G', 'H', cnt);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char c1, c2;
        cin >> c1 >> c2;

        if (getBoss(c1) != getBoss(c2)) {
            setGroup(c1, c2, cnt);
        }
    }

    cout << cnt << "개";

    return 0;
}