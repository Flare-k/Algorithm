#include <iostream>
#include <regex>
#include <vector>
#include <string>
using namespace std;

int main() {
    // 주어진 파일 이름들.
    vector<string> file_names = {"db-123-log.txt", "db-124-log.txt",
                                "not-db-log.txt", "db-12-log.txt",
                                "db-12-log.jpg"};

    regex re("db-\\d*-log\\.txt");

    cout << "db-숫자-log.txt 일 경우 참" << '\n';

    for (const auto &file_name : file_names) {
        // boolalpha 는 bool을 0과 1 대신에 false, true로 표현하게 해줍니다.
        cout << file_name << ": " << boolalpha << regex_match(file_name, re) << '\n';
    }

    // regex_match(비교대상, 정규표현식) -> 매칭되면 true

    return 0;
}