#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char arr[5][9];
char tmp[5][9];
bool check[13];
struct Node {
    int x, y;
};

vector<Node> v;
vector<int> cdt;

void print() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }   
}

bool checkExit(int& sum, int& cnt) {
    if (sum == 26) {
        cnt++;
        sum = 0;
        return true;
    }

    return false;
}

bool checkMagicStar() {
    int cnt = 0;
    int sum = 0;
    // 1
    for (int i = 1; i <= 7; i++) {
        if (i % 2) sum += (arr[1][i] - 'A' + 1);
    }

    if (!checkExit(sum, cnt)) return false;

    // 2
    int idx = 1;
    for (int i = 1; i <= 4; i++) {
        sum += (arr[i][idx++] - 'A' + 1);
    }

    if(!checkExit(sum, cnt)) return false;

    // 3
    idx = 4;
    for (int i = 4; i >= 1; i--) {
        sum += (arr[i][idx--] - 'A' + 1);
    }

    if (!checkExit(sum, cnt)) return false;

    // 4
    for (int i = 1; i <= 7; i++) {
        if (i % 2) sum += (arr[3][i] - 'A' + 1);
    }

    if (!checkExit(sum, cnt)) return false;

    // 5
    idx = 1;
    for (int i = 3; i >= 0; i--) {
        sum += (arr[i][idx++] - 'A' + 1);
    }

    if(!checkExit(sum, cnt)) return false;

    // 6
    idx = 7;
    for (int i = 3; i >= 0; i--) {
        sum += (arr[i][idx--] - 'A' + 1);
    }

    if (!checkExit(sum, cnt)) return false;

    if (cnt == 6) return true;
    return false;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'x') v.push_back({i, j});
            else if (arr[i][j] >= 'A' && arr[i][j] <= 'L') {
                int idx = arr[i][j] - 'A' + 1;
                check[idx] = true;
            }
        }
    }

    memcpy(tmp, arr, sizeof(tmp));

    for (int i = 1; i <= 12; i++) {
        if (!check[i]) cdt.push_back(i);
    }
    
    int size = cdt.size();

    do {
        memcpy(arr, tmp, sizeof(arr));
    
        for (int i = 0; i < size; i++) {
            arr[v[i].x][v[i].y] = (char)('A' + cdt[i] - 1);
        }

        if (checkMagicStar()) {
            print();
            break;
        }

    } while(next_permutation(cdt.begin(), cdt.end()));

    return 0;
}