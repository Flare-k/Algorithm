/*
 한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

 각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.
 >>즉, 모든 종이조각을 다 이용해야 하는 것은 아니다.
 
 제한사항

     numbers는 길이 1 이상 7 이하인 문자열입니다.
     numbers는 0~9까지 숫자만으로 이루어져 있습니다.
     "013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

bool prime(int x){
    if(x < 2)
        return false;
    
    int k = sqrt(x);
    for(int i=2; i<=k; i++){
        if(x%i == 0) return false;
    }
    return true;
}                   //소수를 찾기위한 함수.

int solution(string numbers) {
    int cnt=0;      //소수를 발견했을 때 카운팅
    
    vector<int> num;    //각 자리의 수를 저장하기 위해..
    string sample;
    for(int i=0; i<numbers.size(); i++){
        sample = numbers[i];
        num.push_back(stoi(sample.c_str()));
    }       //입력받은 숫자를 1의 자리인 각 숫자로 변환하여 num이라는 벡터에 저장
    sort(num.begin(), num.end());   //저장한 원소들을 오름차순으로 정렬
    
    
    vector<int> ans;    //전체 결과를 저장할 벡터생성
    do{
        for(int i=0; i<=num.size(); i++){//이 부분 매우중요
            int tmp=0;                   //이 부분 매우중요
            for(int j=0; j<i; j++){      //이 부분 매우중요
                tmp = (tmp*10) + num[j]; //이 부분 매우중요
                ans.push_back(tmp);      //이 부분 매우중요
            }
        }
    }while(next_permutation(num.begin(), num.end()));

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    
    for(int i=0; i<ans.size(); i++){
        if(prime(ans[i])) cnt++;
    }
    
    return cnt;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    string numbers;
    cin>>numbers;
    cout<<solution(numbers)<<'\n';
    return 0;
}


/*

 bool prime(int x){
     if(x < 2)
         return false;
     
     int k = sqrt(x);
     for(int i=2; i<=k; i++){
         if(x%i == 0) return false;
     }
     return true;
 }                   //소수를 찾기위한 함수.

 int solution(string numbers) {
     int cnt=0;      //소수를 발견했을 때 카운팅
     
     vector<int> num;    //각 자리의 수를 저장하기 위해..
     string sample;
     for(int i=0; i<numbers.size(); i++){
         sample = numbers[i];
         num.push_back(stoi(sample.c_str()));
     }       //입력받은 숫자를 1의 자리인 각 숫자로 변환하여 num이라는 벡터에 저장
     sort(num.begin(), num.end());   //저장한 원소들을 오름차순으로 정렬
     
     
     vector<int> ans;    //전체 결과를 저장할 벡터생성
     do{
         for(int i=0; i<=num.size(); i++){
             int tmp=0;
             for(int j=0; j<i; j++){
                 tmp = (tmp*10) + num[j];
                 ans.push_back(tmp);
             }
         }
     }while(next_permutation(num.begin(), num.end()));
     for(int i=0; i<ans.size(); i++){
         cout<<ans[i]<<endl;
     }
     
     sort(ans.begin(), ans.end());
     ans.erase(unique(ans.begin(), ans.end()), ans.end());
     
     for(int i=0; i<ans.size(); i++){
         if(prime(ans[i]))
             cnt++;
     }
     
     return cnt;
 }
 
 
 
 
 bool prime(int x){
     if(x < 2)
         return false;
     
     int k = sqrt(x);
     for(int i=2; i<=k; i++){
         if(x%i == 0) return false;
     }
     return true;
 }

 int solution(string numbers) {
     int cnt=0;
     
     vector<int> temp;
     sort(numbers.begin(), numbers.end());
     do{
         string tmp;
         for(int i=0; i<numbers.size(); i++){
             temp.push_back(int(numbers[i])-'0'); //만약 3자리 수라면 3자리 수만큼 출력을 하고 temp변수에 저장한다.
             tmp.push_back(numbers[i]);
         }

         int tempNum = atoi(tmp.c_str());   //위에서 temp에 저장한 값을 수로 변환
         temp.push_back(tempNum);
         
     }while(next_permutation(numbers.begin(), numbers.end()));
     
     sort(temp.begin(), temp.end());
     temp.erase(unique(temp.begin(), temp.end()), temp.end());
     
     for(int i=0; i<temp.size(); i++){
         if(prime(temp[i])){
          cout<<temp[i]<<endl;
             cnt++;
         }
     }

     
     return cnt;
 }
 
*/
