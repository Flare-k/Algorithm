#include <iostream>
#include <string>
using namespace std;

string randomCard;
char card[4];
int used[6];
int even;   // 짝수
int odd;    // 홀수
int check[999999] = {0};
int crt;

void run(int level, string randomCard, int idx) {
    if (check[idx] == 1) return;

    if (level == 4 && !check[idx]) {
        check[idx] = 1;

        if (idx % 2 == 0) even++;
        else odd++;

        return;
    }

    for (int i = 0; i < 6; i++) {
        if (used[i] == 1) continue;

        used[i] = 1;
        card[level] = randomCard[i];
        crt = stoi(card) - 0;
        run(level + 1, randomCard, crt);
        used[i] = 0;
    }
}

int main() {

    cin >> randomCard;
 
    run(0, randomCard, 0);

    cout << even + odd << " " << even << " "<< odd << '\n';

    return 0;
}