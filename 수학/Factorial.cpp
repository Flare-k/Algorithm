#include <iostream>
using namespace std;
/*
 팩토리얼 구하기
 */
/*
int factorial(int n){
    if(n == 0)
        return 1;
    else{
        return n*factorial(n-1);
    }
}
int zerocount1(int n){
    int temp;
       if(n%5 == 0 && n%25 != 0){
           temp = n/5;
           return temp;
       }
       else if(n%5 == 0 && n%25 == 0){
           temp = n/5 + n/25;
           return temp;
       }
    return 1;
}
int cnt = 0;
int zerocount2(int n){
    if(n%5==0 || n%25==0){
        cnt++;
        n = n/5;
        return zerocount2(n);
    }
    else
        return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    cin>>a;
    
    if(a%5==0 || a%25==0)
        cout<<zerocount1(a)<<'\n';
    
    else if(a%5!=0 && a%25!=0)
        cout<<zerocount2(factorial(a))<<'\n';
    
    
    return 0;
}
*/

/*
 while(n%5==0 || n%25==0){
     cnt++;
     n = n/5;
 }
 return cnt;
 */
/*
 if(n%5==0 || n%25==0){
     cnt++;
     n = n/5;
     return zerocount(n);
 }
 else
     return cnt;
 */


int total = 1;
int cnt = 0;
 
 
int main(){
    int n;
    int i = 1;
    int tmp;
    scanf("%d", &n);
 
    while (n >= i){
        total = total * i;  //자체적으로 팩토리얼을 만듬
        i++;

        while (total % 10 == 0){
            cnt++;
            total = total / 10;
        }

        if (total >= 100000){
            tmp = total / 100000;
            tmp = tmp * 100000;
            total = total - tmp;
        }
    }
 
    printf("%d", cnt);
 
}