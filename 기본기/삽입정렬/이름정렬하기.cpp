#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string name1, string name2) {
    if (name1.length() < name2.length()) return true;
    if (name1.length() > name2.length()) return false;
    if (name1.length() == name2.length()) {
        if (name1 < name2)
            return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> person(n);

    for (int i = 0; i < n; i++) {
        cin >> person[i];
    }

    sort(person.begin(), person.end(), cmp);

    for (int i = 0; i < person.size(); i++) {
        cout << person[i] << '\n';
    }

    return 0;
}