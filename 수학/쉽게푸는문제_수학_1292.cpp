#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;  // 범위 두 구간 입력

    const int MAX = 1001;
    int arr[MAX];
    fill(arr, arr + MAX, 0);    // 배열 초기화

    int target = 1; // 배열에 입력되는 target 변수
    int cnt = 1;    // target 변수가 몇개 남았는지
    for (int i = 1; i < MAX; i++) {
        arr[i] += target;
        cnt--;
        // 만약 target 숫자가 target번 만큼 입력됐다면 다음 숫자로 갱신
        if (cnt == 0) {
            target++;
            cnt = target;
        }
    }

    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += arr[i];
    }
    

    cout << sum;

    return 0;
}