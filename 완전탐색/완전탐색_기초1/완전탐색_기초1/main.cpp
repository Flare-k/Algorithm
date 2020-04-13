/*
 상황에 따라서 n중 for-loop가 필요하다면? -> 재귀호출로 구현해준다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArr = 105;
bool check[105]; // check[i] == true -> 해당 숫자가 이미 나왔음을 체크.

void getResult(int current, int n, int result[]){
    if(current >= n){
        for(int i=0; i<n; i++){
            cout<<result[i]<<' ';
        }
        cout<<'\n';
    }
    else{
        for(int i=1; i<=n; i++){
            if(check[i-1] == false){
                result[current] = i;
                check[i-1] = true;
                
                getResult(current+1, n, result);
                
                check[i-1] = false;
                result[current] = 0;
            }
        }
    }
    
}

int main() {
    int n;
    int arr[105] = {0,};
    cin>>n;
    
    getResult(0, n, arr);
    
    return 0;
}
