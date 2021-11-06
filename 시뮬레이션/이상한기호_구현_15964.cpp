#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long A, B;

int main() {

    cin >> A >> B;

    long long answer = (A + B) * (A - B);
    cout << answer;

    return 0;
}