#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string> words[5];

void split(int idx, string str) {
    int left = 0, right = 0;

    while (1) {
        
        right = str.find(' ', left);

        if (right == -1) {
            words[idx].push_back(str.substr(left));
            break;
        }

        words[idx].push_back(str.substr(left, right - left));
        left = right + 1;
    }

    cout << "Case #" << idx + 1 << ": ";
    for (int i = words[idx].size() - 1; i >= 0; i--) {
        cout << words[idx][i] << ' ';
    }
    cout << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    string str;

    cin.ignore();

    for (int i = 0; i < N; i++) {
        getline(cin, str);
        split(i, str);
    }

    return 0;
}

