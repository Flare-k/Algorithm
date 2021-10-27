#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

int n, m;
int cnt = 0;
vector<int> arr;

/*
void binarySearch(int n) {
    int first = 0;
    int mid = 0;
    int end = arr.size() - 1;

    while (first <= end) {
        mid = (first + end) / 2;
        
        if (n == arr[mid]) {
            cnt++;
            arr.erase(arr.begin() + mid);
            
            binarySearch(n);
            
            return;
        } 
        else {
            if (n < arr[mid]) end = mid - 1;
            else first = mid + 1;
        }
    }
}
*/

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    
    init();
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());
    
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
    
        int lower = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
        int upper = upper_bound(arr.begin(), arr.end(), num) - arr.begin();
    
        if (upper == n - 1 && arr[n - 1] == num) upper++;
    
        cout << upper - lower << " ";
    }

    return 0;
}

/*
10
6 3 2 10 10 10 -10 -10 7 3   -> -10 -10 2 3 3 6 7 10 10 10
8
10 9 -5 2 3 4 5 -10
*/