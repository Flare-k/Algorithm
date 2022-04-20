#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A, B, C;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while (1) {
        cin >> A >> B >> C;

        if (A == 0 && B == 0 && C == 0) break;

        vector<int> triangle = {A, B, C};
        sort(triangle.begin(), triangle.end());

        if (A + B <= C) {
            cout << "Invalid" << '\n';
            continue;
        }

        if (A == B && B == C && A == C) cout << "Equilateral" << '\n';
        else if (A == B || B == C || A == C) cout << "Isosceles" << '\n';
        else cout << "Scalene" << '\n';
    }

	return 0;
}