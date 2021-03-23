#include <iostream>
#include <string>
using namespace std;

char vec[100];
int people[100];    // 인구수
int natCnt[100];    // 나라 카운팅
int isDie[100];     
int n;

char getBoss(char ch) {
    if (vec[ch] == 0) return ch;
    char ret = getBoss(vec[ch]);
    vec[ch] = ret;
    return ret;
}

void setGroup(char c1, char c2) {
    char g1 = getBoss(c1);
    char g2 = getBoss(c2);

    if (isDie[g1] == 1 || isDie[g2] == 1) return;
    if (g1 == g2) return;

    vec[g2] = g1;
    natCnt[g1] += natCnt[g2];
    people[g1] += people[g2];
    natCnt[g2] = 0;
    people[g2] = 0;
}

void war(char t1, char t2) {
    char c1 = getBoss(t1);
    char c2 = getBoss(t2);

    if (isDie[c1] == 1 || isDie[c2] == 1) return;
    if (c1 == c2) return;

    if (natCnt[c1] > natCnt[c2]) {
        isDie[c2] = 1;
        n -= natCnt[c2];
        natCnt[c2] = 0;
        people[c2] = 0;
    }
    else {
        isDie[c1] = 1;
        n -= natCnt[c1];
        natCnt[c1] = 0;
        people[c1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> people['A' + i];
        natCnt['A' + i] = 1;
    }

    int alliOrWar;
    cin >> alliOrWar;
    
    string whatCase;
    char c1, c2;

    for (int i = 0; i < alliOrWar; i++) {
        cin >> whatCase >> c1 >> c2;

        if (whatCase == "alliance") {
            setGroup(c1, c2);
        }
        
        if (whatCase == "war") {
            war(c1, c2);
        }
    }

    cout << n;

    return 0;
}