#include <iostream>
#include <vector>
using namespace std;
/*
 
 1 2 /3 4/ 5 6/ 7 8 / 9 10/ 11 12/ 13 14/ 15 16
          1 2 / 3 4 / 5 6 / 7 8
                1 2 / 3 4
                  1   2
 
 */
int main(){
    int total, kim, imm;
    cin >> total >> kim >> imm;
    int cnt=0;

    while(kim != imm){
        kim = kim / 2 + kim % 2;
        imm = imm / 2 + imm % 2;
        cnt += 1;
    }
    
    cout << cnt << '\n';
    
    return 0;
}
