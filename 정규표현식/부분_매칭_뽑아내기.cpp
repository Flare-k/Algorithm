#include <iostream>
#include <regex>
#include <vector>
using namespace std;

int main() {
    vector<string> phone_numbers = {"010-1234-5678", "010-123-4567",
                                    "011-1234-5567", "010-12345-6789",
                                    "123-4567-8901", "010-1234-567"};

    regex re("[01]{3}-\\d{3,4}-\\d{4}");
    // [01] = 0 또는 1 , {3} = 해당 종류의 문자가 세번 나타날 수 있음

    for (const auto &number : phone_numbers) {
        cout << number << ": " << boolalpha << regex_match(number, re) << '\n';
    }

    cout << '\n';

    // 만약 특정 부분을 추출하고 싶다면? capture group
    regex capture("[01]{3}-(\\d{3,4})-\\d{4}");
    // 캡쳐할 부분을 (\\d{3,4}) 처럼 ()로 감싼다

    smatch match;   // 매칭된 결과를 string으로 보관
    for (const auto &number : phone_numbers) {
        if (regex_match(number, match, capture)) {  // 정규표현식에 만족한다면 match에 저장!
            for (size_t i = 0; i < match.size(); i++) { // match엔 일치하는 문자열과 ()로 감싼 특정 문자열이 순서대로 저장된다.
                cout << "Match : " << match[i].str() << '\n';
            }
            cout << "-----------------------\n";
        }
    }


    return 0;
}