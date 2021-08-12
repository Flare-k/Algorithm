#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr;
int maxx = -21e8;
int sum;

void run() {
    if (arr.size() == 2) {
        maxx = max(maxx, sum);
        return;
    }

    for (int i = 1; i < arr.size() - 1; i++) {
        int tmp = arr[i];
        
        sum += arr[i - 1] * arr[i + 1];
        arr.erase(arr.begin() + i);
        run();
        arr.insert(arr.begin() + i, tmp);
        sum -= arr[i - 1] * arr[i + 1];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    run();

    cout << maxx << '\n';

    return 0;
}