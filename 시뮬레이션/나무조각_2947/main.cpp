#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[5];

    for (int i = 0; i < 5; i++){
        cin >> arr[i];
    }

    int cnt;
    int i = 0;
    while(cnt != 5-1){
        cnt = 0;
        bool check = false;
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i+1]);
            check = true;
        }
        
        if (check){
            for (int i = 0; i < 5 - 1; i++) {
                if (arr[i] + 1 == arr[i + 1]) {
                    cnt++;
                }
                cout << arr[i] << " ";
            }
            cout << arr[4] << '\n';
        }
        i++;
        if (i == 5) i = 0;
    }

    return 0;
}