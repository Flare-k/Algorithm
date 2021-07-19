#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
연식 입력
해당 차량 출력
*/

unordered_multimap<int, string> m;

int main() {

    m.insert({1995, "Benz"});
    m.insert({2006, "Sonata"});
    m.insert({2015, "Sonata"});
    m.insert({1998, "Audi"});
    m.insert({2006, "Audi"});

    int num;
    cin >> num;

    auto number = m.equal_range(num);

    for (auto i = number.first; i != number.second; ++i) {
        cout << i->second << '\n';
    }

    return 0;
}