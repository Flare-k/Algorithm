#include <iostream>
#include <vector>
using namespace std;

//조합한 수가 3129이 넘는 경우가 총 몇개인지 출력

vector<int> cards;
int used[4];
int cnt = 0;

void run(int level, int sum) {
    if (level == 4) {
        if (sum > 3129) cnt++;
        return;
    }

    for (int i = 0; i < cards.size(); i++) {
        if (level == 0 && cards[i] < 3) continue;   // 1000의 자리수가 3보다 작은 경우는 모두 배제
        if (used[i] == 1) continue;

        used[i] = 1;
        run(level + 1, sum * 10 + cards[i]);
        used[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    for (int i = 0; i < 4; i++) {
        cin >> n;
        cards.push_back(n);
    }
    
    run(0, 0);

    cout << cnt;

    return 0;
}