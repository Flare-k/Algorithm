#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Knuth-Morris-Pratt Algorithm
 * 접두사와 접미사의 개념을 활용해 반복되는 연산 최소화
 * 
 */

vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);

    int j = 0;
    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }

    return table;
}

void KMP(string parent, string pattern) {
    vector<int> table = makeTable(pattern);

    int parentSize = parent.size();
    int patternSize = pattern.size();

    int j = 0;
    for (int i = 0; i < parentSize; i++) {
        while (j > 0 && parent[i] != pattern[j]) {
            j = table[j - 1];
        }

        if (parent[i] == pattern[j]) {
            if (j == patternSize - 1) {
                cout << i - patternSize + 2 << "번째에서 찾았습니다." << '\n';
                j = table[j];
            }
            else {
                j++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string parent = "ababacaabaabacaaba";
    string pattern = "abacaaba";

    vector<int> table = makeTable(pattern);

    for (int num : table) {
        cout << num << ' ';
    }
    cout << '\n';

    KMP(parent, pattern);

    return 0;
}