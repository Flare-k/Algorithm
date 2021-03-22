#include <iostream>
using namespace std;

char vec[100];

char getBoss(int ch) {
    if (vec[ch] == 0) return ch;

    char ret = getBoss(vec[ch]);
    vec[ch] = ret;
    return ret;
}

void setGroup(char c1, char c2) {
    char g1 = getBoss(c1);
    char g2 = getBoss(c2);
    if (g1 == g2) return;

    // 만약 g1이 문자, g2가 숫자라면
    if (g1 >= 'A' && g1 <= 'Z') {
        vec[g2] = g1;
    }
    else {
        vec[g1] = g2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    char input1, input2;
    for (int i = 0; i < N; i++) {
        cin >> input1 >> input2;
        
        setGroup(input1, input2);
    }

    for (int i = 1; i <= K; i++) {
        cout << getBoss('0' + i);
    }

    return 0;
}