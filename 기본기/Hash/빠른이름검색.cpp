#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um = {
    {"POP", 1}, {"TOM", 1}, {"MC", 1}, {"JASON", 1}, {"KFC", 1}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        if (um.count(name)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}