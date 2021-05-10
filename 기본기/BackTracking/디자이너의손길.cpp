#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int maxScore = -21e8;

string str;
int n;


int calc() {
    int sum = 0;

    for (int i = 1; i < str.length(); i++) {
        char c1 = str[i - 1];
        char c2 = str[i];

        if (c1 == c2) sum -= 50;
        if (abs(c1 - c2) <= 5) sum += 3;
        if (abs(c1 - c2) >= 20) sum += 10;
    }

    return sum;
}

void run(int level) {
    if (level == n) {
        int sum = calc();
        if (maxScore <= sum) maxScore = sum;
        return;
    }

    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = i + 1; j < str.length(); j++) {
            swap(str[i], str[j]);
            run(level + 1);
            swap(str[i], str[j]);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 이웃한 글자가 같은글자일때? -50
    // 2. 같은 글자는 아니지만 이웃한 글자의 간격이 5 이하? +3
    // 3. 이웃한 글자의 간격이 20이상? +10
    // n번 만큼 swap시 가장 점수가 클 때

    cin >> str >> n;
    run(0);

    cout << maxScore << '\n';

    return 0;
}
/*

AACHZ
3
> 26

LGTJRANDO
4
> 21

*/