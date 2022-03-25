#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Knuth-Morris-Pratt Algorithm
 * 접두사와 접미사의 개념을 활용해 반복되는 연산 최소화
 * 
 */

// 각 위치에서 접두사와 접미사 간의 일치하는 길이만큼 테이블 갱신
// a b a c a a b a
// 0 0 1 0 1 1 2 3
vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();   // 찾고자 하는 문자열의 길이
    vector<int> table(patternSize, 0);

    int j = 0;
    for (int i = 1; i < patternSize; i++) {
        // j가 0 이상인데, i번째와 j번째가 일치하지 않는다면
        // j 위치에서 1을 뺀 그 인덱스의 데이블 값으로 j 값을 변경
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

    string parent = "abacaabaabacaaba";
    string pattern = "abacaaba";

    vector<int> table = makeTable(pattern);

    for (int num : table) {
        cout << num << ' ';
    }
    cout << '\n';

    KMP(parent, pattern);

    return 0;
}