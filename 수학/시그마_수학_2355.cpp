#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long A, B;
    cin >> A >> B;
    
    if (A > B) swap(A, B);

    long long answer = (B * (B + 1) - A * (A - 1)) / 2;

    cout << answer << '\n';

    return 0;
}