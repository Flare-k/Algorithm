#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt=0;

bool prime(int arr[], int length){
    for(int i=0; i<length; i++){
        if(arr[i] == 1)
            return false;
        else{
            for(int j=2; j<=arr[i]; j++){
                if(arr[i]%j == 0)
                    return false;
            }
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0; //소수가 될 수 있는 경우의 수를 카운트
    int arr[numbers.size()];
    
    for(int i = 0; i < numbers.size(); i++){
        arr[i] = int(numbers[i]-48);     //숫자가 적힌 문자열을 정수형 배열에 삽입
        cout<<arr[i]<<" ";
    }
    unsigned long length = numbers.size();
    if(prime(arr, length))
        answer++;
    
    return answer;
}

int main() {
    string numbers;
    cin>>numbers;
    cout<<solution(numbers)<<'\n';
    
    return 0;
}

/*
 경우의 수..
 1. 각 수를 1의 자리로 봤을 때 소수인 경우.
 2. 맨 앞에 숫자를 고정후 뒤에 자리만 바꿔가면서 소수인지 확인하는 방법
 
 기본적으로 길이x2 + 낱개의 경우가 존재..
 */
