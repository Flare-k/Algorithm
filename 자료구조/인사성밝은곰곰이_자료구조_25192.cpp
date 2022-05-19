#include <iostream>
#include <string>
#include <set>
using namespace std;

int answer, N;
set<string> list;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        if (name == "ENTER") {
            answer += list.size();
            list.clear();
        }
        else list.insert(name);
    }

    answer += list.size();

    cout << answer << '\n';

    return 0;
}