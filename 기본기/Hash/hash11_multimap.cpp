#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// unordered_multimap은 중복된 키값을 가질 수 있다.
unordered_multimap<string, int> umm;

int main() {

    /*
    기존 unordered_map은 umm["ABC"] = 17하면 입력됐지만
    unordered_multimap은 insert를 이용한다.
    */

    // 저장
    umm.insert({"ABC", 17});
    umm.insert({"ABC", 35});
    umm.insert({"ABC", 50});

    // 읽기 v1.
    for (auto i = umm.find("ABC"); i != umm.end(); ++i) {
        if (i->first != "ABC") break;
        cout << i->first << ": " << i->second << '\n';
    }

    // 읽기 v2. (공식버전, 속도는 더 빠름)
    auto mi = umm.equal_range("ABC");   // ABC 키값의 시작&끝 주소값을 할당
    for (auto i = mi.first; i != mi.second; ++i) {
        cout << i->first << ": " << i->second << '\n';
    }

    return 0;
}