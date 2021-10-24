#include <iostream>
#include <vector>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {

    for (int i = 0; i < apples.size(); i++) {
        apples[i] = a + apples[i];
    }

    for (int i = 0; i < oranges.size(); i++) {
        oranges[i] = b + oranges[i];
    }

    int appleCnt = 0, orangeCnt = 0;

    for (int apple : apples) {
        if (s <= apple && apple <= t) appleCnt++;
    }
    
    for (int orange : oranges) {
        if (s <= orange && orange <= t) orangeCnt++;
    }

    cout << appleCnt << '\n' << orangeCnt;
}

int main() {
    vector<int> apples = {2, 3, -4};
    vector<int> oranges = {3, -2, -4};

    countApplesAndOranges(7, 10, 4, 12, apples, oranges);

    return 0;
}