#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
int N;
long long M;

void bs() {
    int first = 1;
    int end = arr.back();
    int mid;

    while (first <= end) {
        mid = (first + end) / 2;
        long long sum = 0;

        for (int num : arr) {
            if (num < mid) sum += num;
            else sum += mid;
        }

        if (sum > M) end = mid - 1;
        else first = mid + 1;
    }

    cout << end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    
    long long sum = 0;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cin >> M;

    sort(arr.begin(), arr.end());

    if (M >= sum) cout << arr.back();
    else bs();

    return 0;
}