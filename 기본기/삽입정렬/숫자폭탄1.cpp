#include <iostream>
#include <vector>
using namespace std;

/*
  만약 17개의 폭탄을 아래와 같이 입력받았다면,
  5 4 5 1 1 1 1 1 2 2 2 3 3 3 3 8 1
  남은 폭탄은 5 4 5 1 1 3 8 1 입니다.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int bomb[n];

    for (int i = 0; i < n; i++) {
        cin >> bomb[i];
    }


    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt = 1;

        int idx = i;
        for (int j = idx; j > 0; j--) {
            if (bomb[j - 1] == bomb[j]) {
                cnt++;
            }
            else {
                break;
            }
        }
        
        if (cnt == 3) {
            for (int k = idx; k > idx - 3; k--) {
                bomb[k] = 0;
            }
        }
    }

    vector<int> answer;

    for (int i = 0; i < n; i ++) {
        if (bomb[i] != 0) {
            answer.push_back(bomb[i]);
        }
    }

    sort(answer.begin(), answer.end());

    for (int res : answer) {
        cout << res << ' ';
    }
    

    return 0;
}