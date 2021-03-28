#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
const int MAX = 10000+1;
int res[MAX] = {0};
/*
 첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.
 */

int main(){
    int a;
    scanf("%d", &a);
    
    for (int i = 0; i < a; i++) {
        int num;
        scanf("%d", &num);
        res[num] += 1;
    }
    
    
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < res[i]; j++) {
            printf("%d\n", i);
        }
    }
}
