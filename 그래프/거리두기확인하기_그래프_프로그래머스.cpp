#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    

    for (auto place : places) {
        int cnt = 0;
        bool flag = false;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cnt = 0;
                char status = place[i][j];
                
                if (status == 'P') cnt++;
                if (status == 'X') continue;

                if (status == 'P' || status == 'O') {
                    
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                        if (place[nx][ny] == 'P') {
                            cnt++;
                            if (cnt >= 2) {
                                flag = true;
                                break;
                            }
                        }
                    }
                }
                
                if (flag) break;
            }
            if (flag) break;
        }

        if (flag) answer.push_back(0);
        else answer.push_back(1);
    }


    return answer;
}

int main() {

    vector<vector<string>> places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };

    vector<int> sol = solution(places);

    for (int s : sol) {
        cout << s << ' ';
    }

    return 0;
}