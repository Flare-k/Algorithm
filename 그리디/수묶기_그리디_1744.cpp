#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 블로그 참고했음..
 * 수를 묶음에 있어서 1과 묶는 경우 매우 손해이다. 그렇기 때문에 1의 경우는 그냥 더하기만 해준다.
 * 0이 나올 경우 음수와 곱해주는 경우가 최대값을 구할 수 있는 최선이다. 따라서 0이 나오면 카운팅만하고 나중에 음수 최대값을 그만큼 pop해주자.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 수열의 개수
    cin >> n;
    
    vector<int> pos;    // 양수를 담는 벡터
    vector<int> neg;    // 음수를 담는 벡터
    int zeroCnt = 0;    // 0의 개수
    int oneCnt = 0;     // 1의 개수

    for (int i = 0; i < n; i ++) {
        int num;
        cin >> num;

        if (num == 1) {
            oneCnt++;
        }
        else if (num > 0) {
            pos.push_back(num);
        }
        else if (num < 0) {
            neg.push_back(num);
        }
        else {
            zeroCnt++;
        }
    }

    sort(pos.rbegin(), pos.rend()); // 양수는 내림차순
    sort(neg.begin(), neg.end());   // 음수는 오름차순

    // 양수의 길이가 홀수라면, 두 수를 곱하기 어려우므로 제일 문제없는 1을 추가해준다.
    if (pos.size() % 2 == 1) {
        pos.push_back(1);
    }
    // 음수의 길이가 홀수라면, 만약 0이 없다면 0을 추가. 아니면 1 추가 
    // -> 0이 있었다면 가장 큰 음수와 곱해주기 위해 0을 추가
    // -> 0이 없었다면 낱개만 더해야하므로 1 추가
    if (neg.size() % 2 == 1) {
        neg.push_back(zeroCnt > 0 ? 0 : 1);
    }

    // 수 묶기
    int sum = 0;
    for (int i = 0; i < pos.size(); i += 2) {
        sum += (pos[i] * pos[i + 1]);
    }
    for (int i = 0; i < neg.size(); i += 2) {
       sum += (neg[i] * neg[i + 1]);
    }
    sum += oneCnt;

    cout << sum;

    return 0;
}