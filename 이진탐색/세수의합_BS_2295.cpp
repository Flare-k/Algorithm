#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

int N;
int arr[MAX];
vector<int> vec;

bool binarySearch(int s, int e, int target) {
    while (s <= e){
        int mid = (s + e) / 2;
        
        if (vec[mid] == target) return true;

        if (vec[mid] < target) s = mid + 1;
        else if (vec[mid] > target) e = mid - 1;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }    
    
    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            vec.push_back(arr[i] + arr[j]);
        }
    }

    sort(vec.begin(), vec.end());

    int answer = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (binarySearch(0, vec.size(), arr[j] - arr[i])) {
                answer = max(answer, arr[j]);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}