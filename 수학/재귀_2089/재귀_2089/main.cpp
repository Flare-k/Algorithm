#include <iostream>
#include <cmath>
#include <algorithm>
#define endl "\n"
using namespace std;
/*
 -2진수_수학/재귀_2089
 */
void go(int n){
    if(n == 0)
        return;
    
    if(n%2 == 0){
        go(-(n/2));
        cout << "0";
    }
    else{
        if(n > 0)
            go(-(n/2));
        else
            go(-(n/2) + 1);
        cout << "1";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;
    if(num == 0){
        cout << "0" << endl;
        return 0;
    }
    else
        go(num);
    
    cout<<endl;
    return 0;
}
