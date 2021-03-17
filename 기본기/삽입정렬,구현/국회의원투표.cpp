#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
  가장 투표를 많이 받은 국회의원을 찾아주세요.
  (같은 표를 받았다면, 번호가 더 빠른 사람이 당선됩니다.)

  국회의원들은 숫자로 나타내고, 사람들은 투표할 숫자와 이름으로 입력됩니다.
  당선된 국회의원이 누구에게 투표를 받았는지를 출력해주세요.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, vote;
    cin >> num >> vote;

    vector<string> candidate[num];

    int a;
    string b;
    for (int i = 0; i < vote; i++) {
        cin >> a >> b;
        candidate[a].push_back(b);
    }

    int idx = 101;
    int len = candidate[0].size();
    for (int i = 1; i < num; i++) {
        if (len < candidate[i].size()) {
            len = candidate[i].size();
            idx = i;
        }
    }

    for (int i = 0; i < candidate[idx].size(); i++) {
        cout << candidate[idx][i] << ' ';
    }

    return 0;
}
