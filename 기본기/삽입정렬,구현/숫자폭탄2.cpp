#include <iostream>
#include <vector>
using namespace std;

/*
  만약 17개의 폭탄을 아래와 같이 입력받았다면,
  5 4 5 1 1 1 1 1 2 2 2 3 3 3 3 8 1
  남은 폭탄은 5 4 5 1 1 3 8 1 입니다.
*/
const int MAX = 10001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int bomb[MAX] = {0};

    vector<int> ans;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        bomb[num]++;

        ans.push_back(num);
        int len = ans.size();
        if (i > 2) {
            if (ans[len - 1] == ans[len - 2] && ans[len - 2] == ans[len - 3]) {
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
                bomb[num] -= 3;
            }
        }
    }


    for (int i = 1; i < MAX; i++) {
        while (bomb[i]--) {
            cout << i << ' ';
        }
    }

    return 0;
}