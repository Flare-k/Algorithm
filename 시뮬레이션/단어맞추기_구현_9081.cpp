#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    string str;

    for (int i = 0; i < N; i++) {
        cin >> str;

        string target = str;
        string answer;
        int cnt = 0;

        do {
            if (target == str || cnt < 2){
                answer = target;
                cnt++;
                if (cnt == 2) break;
            }
        } while (next_permutation(target.begin(), target.end()));

        cout << answer << '\n';
    }

    return 0;
}