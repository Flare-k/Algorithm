#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Node {
    string name;
    int age, tall;
};

unordered_map<string, Node> m;

int main() {
    
    // 모든 입력조건에 대해 검색이 가능하도록..
    string name, age, tall;
    for (int i = 0; i < 4; i++) {
        cin >> name >> age >> tall;
        m[name] = {name, stoi(age), stoi(tall)};
        m[age] = {name, stoi(age), stoi(tall)};
        m[tall] = {name, stoi(age), stoi(tall)};
    }

    string inputCond;
    cin >> inputCond;

    cout << m[inputCond].name << ' ' << m[inputCond].age << ' ' << m[inputCond].tall;
    
    return 0;
}