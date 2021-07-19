#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

unordered_multimap<char, int> m;

struct Node {
    char name;
    int id;
};

vector<Node> employee = {{'A', 21}, {'E', 15}, {'E', 6}, {'A', 15}, {'E', 34}, 
                        {'B', 32}, {'C', 35}, {'C', 36}, {'D', 14}, {'A', 3}};

int main() {

    for (int i = 0; i < employee.size(); i++) {
        m.insert({employee[i].name, employee[i].id});
    }

    char name;
    cin >> name;

    auto iter = m.equal_range(name);
    for (auto i = iter.first; i != iter.second; ++i) {
        cout << i->second << ' ';
    }

    return 0;
}