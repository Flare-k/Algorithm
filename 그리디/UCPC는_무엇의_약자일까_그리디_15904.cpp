#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string sentence;
    getline(cin, sentence);

    string ucpc = "UCPC";
    int cnt = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ucpc[cnt]) {
            cnt++;
        }
    }

    if (cnt == 4) {
        cout << "I love UCPC";
    }
    else {
        cout << "I hate UCPC";
    }

    return 0;
}