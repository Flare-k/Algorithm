#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Node {
    string player;
    string cardNum;
    int price;
};

unordered_map<string, Node> m;

int main() {
    
    string player, cardNum;
    int price;
    for (int i = 0; i < 3; i++) {
        cin >> player >> cardNum >> price;
        m[player] = {player, cardNum, price};
        m[cardNum] = {player, cardNum, price};
    }

    string inputCond;
    cin >> inputCond;

    cout << m[inputCond].price;
   
    return 0;
}