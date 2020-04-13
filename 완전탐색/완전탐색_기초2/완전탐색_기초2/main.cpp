/*
 재귀함수를 이용하여 n개중 r를 뽑았을 때 알파벳 순열 출력하기.
 */
#include <iostream>
using namespace std;

int n,r;
const int MAX = 105;
char result[MAX];
bool check[MAX];        //check[i] == true --> 알파벳 i가 이미 나왔음.

void getResult(int x){
    //x번째 for문을 돌려야 함.
    if(x>=r){
        for(int i=0; i<r; i++){
            cout<<result[i]<<' ';
        }
        cout<<'\n';
    }
    else{
        for(int i=0; i<n; i++){
            char alpha = i+'a';
            if(check[i] == false){  //i번째에 원하는 알파벳이 없다면
                result[x] = alpha;  //x번째에 알파벳을 넣어준다.
                check[i] = true;    //result안에 들어갔으니 check도 true로..
                
                getResult(x+1);     //그 다음 for문을 수행시키기 위해!
                //x+1, x+2 ... 모든 경우를 마무리 하고..
                //이제 x번째에 i+1의 경우를 시작해야 함..(즉, result[0]=a가 끝나고 b를 넣을 차례.
                
                check[i] = false;   //false로 안해주면 다음 인덱스에서 a가 나올 수 없다.
                result[x] = 0;
                
            }
        }
    }
}

int main() {
    cin>>n>>r;
    getResult(0);
    
    return 0;
}
