#include <iostream>
using namespace std;
/*
 조합 팩토리얼의 0개수 구하기
 */
int total_n = 1;
int total_r = 1;
int total_nr = 1;
int cnt_nr = 0;
 
int main(){
    int n,r;
    int i = 1, j = 1, k = 1;
    int tmp;
    cin >> n >> r;
 
    while (n >= i){
        total_n = total_n * i;  //자체적으로 팩토리얼을 만듬
        i++;
    }// n!

    while (r >= j){
        total_r = total_r * j;  //자체적으로 팩토리얼을 만듬
        j++;
    }// r!

     while (n - r >= k){
         total_nr = total_nr * k;  //자체적으로 팩토리얼을 만듬
         k++;
     }// r!

    int result;
    
    result = total_n/(total_nr*total_r);

    cout << result << endl;
    
    while (result % 10 == 0){
        cnt_nr++;
        result = result / 10;
    }

    if (result >= 100000){
        tmp = result / 100000;
        tmp = tmp * 100000;
        result = result - tmp;
    }
 
    cout << cnt_nr << endl;
}


/*
 while (n >= i)
 {
     total_n = total_n * i;  //자체적으로 팩토리얼을 만듬
     i++;
     while (total_n % 10 == 0){
         cnt_n++;
         total_n = total_n / 10;
     }
     if (total_n >= 100000){
         tmp_1 = total_n / 100000;
         tmp_1 = tmp_1 * 100000;
         total_n = total_n - tmp_1;
     }
 }// n!
 */
