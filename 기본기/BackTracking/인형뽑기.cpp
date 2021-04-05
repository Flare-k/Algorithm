#include <iostream>
#include <vector>
using namespace std;
// Type 1 = 위, 중앙, 좌, 우, 아래
string type1(int N, int r, int c, string tmp, vector<vector<char>> machine) {
    if (r - 1 >= 0) {
        tmp += machine[r - 1][c];
    }
    tmp += machine[r][c];
    if (c - 1 >= 0) {
        tmp += machine[r][c - 1];
    }
    if (c + 1 < N) {
        tmp += machine[r][c + 1];
    }
    if (r + 1 < N) {
        tmp += machine[r + 1][c];
    }

    return tmp;
}

// Type 2 = 왼위, 중앙, 오위, 오아, 왼아
string type2(int N, int r, int c, string tmp, vector<vector<char>> machine) {
    if (r - 1 >= 0 && c - 1 >= 0) {
        tmp += machine[r - 1][c - 1];
    }
    tmp += machine[r][c];
    if (r - 1 >= 0 && c + 1 >= 0) {
        tmp += machine[r - 1][c + 1];
    }
    if (r + 1 < N && c + 1 < N) {
        tmp += machine[r + 1][c + 1];
    }
    if (r + 1 < N && c - 1 >= 0) {
        tmp += machine[r + 1][c - 1];
    }

    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K; // 기계의 크기, 집게 명령 횟수
    cin >> N >> K;

    vector<vector<char>> machine(N, vector<char>(0));
    // 기계 정보    
    char doll;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> doll;
            machine[i].push_back(doll);
        }   
    }

    // 집게의 시작 좌표 & 타입 ex, 1 1 1 = (1, 1) & Type 1
    // Type 1 = 위, 중앙, 좌, 우, 아래
    // Type 2 = 왼위, 중앙, 오위, 오아, 왼아
    
    int r, c, type;
    vector<string> ans;
    while (K--) {
        string tmp = "";
        cin >> r >> c >> type;

        if (type == 1) {
            tmp = type1(N, r, c, tmp, machine);
        }
        else {
            tmp = type2(N, r, c, tmp, machine);
        }

        ans.push_back(tmp);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }


    return 0;
}