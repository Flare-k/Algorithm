#include <iostream>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    scanf("%d", &n);
    
    int div = 2;
    
    while (n != 1){
        if (n % div == 0){
            n /= div;
            printf("%d\n", div);
        }
        else{
            div++;
        }
    }
    
    return 0;
}