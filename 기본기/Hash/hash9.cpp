#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


unordered_map<string, int> thief;
unordered_map<string, int> town = {
    {"A", 30}, {"B", 20}, {"O", 30}, {"CD", 50},
    {"A", 10}, {"T", 10}, {"A", 10}, {"G", 20},
};

string map[2][4] = {
    "A", "B", "O", "CD",
    "A", "T", "A", "G"
};

int main() {
    
    thief["B"] = 4;
    thief["T"] = 2;
    thief["ABC"] = 6;
    thief["TS"] = 5;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            string t = map[i][j];
            
            if (thief.count(t)) cout << thief[t] << ' ';
            else cout << town[t] << ' ';
        }
        cout << '\n';
    }

    return 0;
}