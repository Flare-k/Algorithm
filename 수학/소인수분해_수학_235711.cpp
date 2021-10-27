#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 10000001;
int arr[MAX];
// 2 3 5 7 11

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    int idx = 0;

    while (num--) {
        memset(arr, 0, sizeof(arr)); idx++;
        int temp = 0;
        int a; 
        
        cin >> a;
        
        for (int i = 2; i * i <= a; i++) {
            while (a % i == 0) {
                arr[i]++;
                a /= i;
            }
            temp = a;
        }
        
        arr[a] = a/temp;
        
        cout << "#" << idx << ' ' << arr[2] << ' ' << arr[3] << ' ' << arr[5] << ' ' << arr[7] << ' ' << arr[11] << '\n';
    }
    
    return 0;
}