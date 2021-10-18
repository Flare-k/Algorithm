#include <iostream>
using namespace std;

// 수식으로 풀이
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>> N;

    cout << (N % 2 ? "SK" : "CY");

    return 0;
}