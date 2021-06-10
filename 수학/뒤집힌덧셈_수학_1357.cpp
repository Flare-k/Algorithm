#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string left, right;
    cin >> left >> right;

    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());

    string ans = to_string(stoi(left) + stoi(right));
    reverse(ans.begin(), ans.end());

    cout << stoi(ans);

    return 0;
}