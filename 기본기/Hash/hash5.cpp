#include <iostream>
#include <unordered_map> // HASH
#include <map>  // BST
using namespace std;

unordered_map<int, int> hashMap;
map<int, int> bst;

int main() {

    hashMap[-5] = 1;
    hashMap[-7] = 1;
    hashMap[6] = 1;
    hashMap[3] = 1;

    cout << "------------- HASH MAP -------------\n";
    for (auto i = hashMap.begin(); i != hashMap.end(); ++i) {
        cout << "{ key : " << i -> first << ", value : " << i ->second << '\n';
    }

    bst[-5] = 1;
    bst[-7] = 1;
    bst[6] = 1;
    bst[3] = 1;
    
    cout << "------------- BST -------------\n";
    for (auto i = bst.begin(); i != bst.end(); ++i) {
        cout << "{ key : " << i -> first << ", value : " << i ->second << '\n';
    }
    return 0;
}