#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int arr[MAX];
    memset(arr, 0, sizeof(arr));
    
    arr[0] = 1;
    arr[1] = 3; // 0(1개) + 1(2개)

    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i - 2] + arr[i - 1] * 2) % 9901;
    }


    cout << arr[n] % 9901;

    return 0;
}