#include <iostream>
#include <string>
using namespace std;

/*
     B
   / | \
  A  |  C
   \ |
     E

    사이클이 있는 그래프인지 없는 그래프인지 찾아라.

    서로 같은 그룹이 아니면 그룹을 맺고 같은 그룹이라면 사이클인 경우이다.
    union find가 사용되는 대표적인 케이스가 cycle을 만드는 경우이다. 
 */

int vec[200];

char getBoss(char ch) {
    if (vec[ch] == 0) return ch;
    char res = getBoss(vec[ch]);
    vec[ch] = res;
    return res;
}

void setGroup(char c1, char c2) {
    char g1 = getBoss(c1);
    char g2 = getBoss(c2);
    if (g1 == g2) return;
    vec[g2] = g1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string cycle[4] = {
        "AB",
        "BE",
        "CB",
        "AE"
    };

    for (int i = 0; i < 4; i++) {
        if (getBoss(cycle[i][0]) == getBoss(cycle[i][1])) {
            cout << "cycle 발견" << '\n';
            return 0;
        }

        // 같은 그룹이 아니면 그룹맺기
        setGroup(cycle[i][0], cycle[i][1]);
    }

    cout << "cycle 미발견" << '\n';

    return 0;
}