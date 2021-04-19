#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string medi;
char path[4];
vector<string> check;

bool checking(string tmp) {
    for (int i = 0; i < check.size(); i++) {
        if (check[i] == tmp) return true;
    }
    return false;
}

void run(int level, int start) {
    if (level == 3) {
        if (checking(path)) return;

        cout << path << '\n';
        check.push_back(path);
        return;
    }

    for (int i = start; i < medi.length(); i++) {
        path[level] = medi[i];
        run(level + 1, i);
        path[level] = 0;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    check.push_back("123");
    cin >> medi;
    sort(medi.begin(), medi.end());

    run(0, 0);

    return 0;
}