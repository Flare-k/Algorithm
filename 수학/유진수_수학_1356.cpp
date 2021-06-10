#include <iostream>
#include <string>
using namespace std;

int mat(string s) {
    int ans = 1;

    for (char num : s) {
        ans *= (num - '0');
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    cin >> num;

    bool check = false;
    for (int i = 1; i < num.length(); i++) {
        string left, right;

        left = num.substr(0, i);
        right = num.substr(i);
        if (mat(left) == mat(right)) {
            check = true;
            break;
        }
    }

    if (check) cout << "YES";
    else cout << "NO";

    return 0;
}