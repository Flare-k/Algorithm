#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> farm(3, vector<int>(3));

    int n;
    cin >> n;

    int dx, dy;
    for (int i = 0; i < n; i++) {
        cin >> dx >> dy;

        int axis;
        cin >> axis;
        farm[dx][dy] += axis;
    }

    int wind;
    cin >> wind;

    for (int i = 0; i < wind; i++) {
        int strongWind;
        cin >> strongWind;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (farm[i][j] % 10 > strongWind) {
                    farm[i][j] -= strongWind;
                }
                else if (farm[i][j] != 0){
                    farm[i][j] /= 10;
                }
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (farm[i][j] != 0) {
                while (farm[i][j] != 0) {
                    farm[i][j] /= 10;
                    cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}