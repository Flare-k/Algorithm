#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> um;

int main() {

    um["BTS"] = 1;
    um["AAA"] = 2;
    um["BBB"] = 3;
    um["CCC"] = 4;
    um["DDD"] = 5;

    string str;
    cin >> str;

    if (um.count(str)) cout << "발견";
    else cout << "미발견";

    return 0;
}

/*
원본 값 = 키 값
변환해주는 함수 = 해쉬 함수
변환을 거친 인덱스 = 해쉬코드
값을 담는 곳 = 버킷

key 값을 인덱스로 쓰는 것이 DAT(Direct Access TAble)인데 DAT는
    - 음수 값
    - 큰 수
    - 문자열
일 때는 인덱스로 사용하는데에 한계가 있다.

해쉬 테이블은 키 값을 인덱스로 바로 쓰는 것이 아니라 키 값을 해쉬 함수를 거쳐서
해쉬 코드를 얻어내고 해쉬 코드를 버킷의 인덱스로 쓰는 것이다. key -> hash
function -> hash code = index -> bucket[index]
*/
