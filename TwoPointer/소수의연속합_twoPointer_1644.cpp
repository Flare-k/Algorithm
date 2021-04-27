#include <iostream>
#include <vector>
using namespace std;

const int MAX = 4000001;
int arr[MAX];

void erathosthenes(){
    arr[0] = arr[1] = 0;
    for (int i = 2; i < MAX; i++) {
        arr[i] = i; // 초기화
    }
    
    for (int i = 2; i <= MAX; i++) {
        if (arr[i] == 0) continue;   // 이미 체크된 수의 배수는 확인하지 않는다.
        for (int j = i + i; j <= MAX; j += i) {    // i를 제외한 i의 배수들은 0으로 체크한다.
            arr[j] = 0;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    erathosthenes();

    vector<int> res;

    for (int i = 0; i < MAX; i++) {
        if (arr[i]) res.push_back(arr[i]);
    }

    int target, sum = 0;
    cin >> target;

    int len = res.size();
    int startIdx = 0;
    int cnt = 0;
    /*
    for (int i = startIdx; i < len; i++) {
        sum += res[i];
        if (sum == target) {
            sum = 0;
            i = startIdx++;
            cnt++;
        }
        else if (sum > target) {
            sum = 0;
            i = startIdx++;
        }
    }
    */
   int endIdx = 0;

    while (1) {
        if (sum >= target) {
            sum -= res[startIdx++];
        }
        else if (endIdx == len) {
            break;
            }
        else {
            sum += res[endIdx++];
        }

        if (sum == target) cnt++;
    }

    cout << cnt;

    return 0;
}