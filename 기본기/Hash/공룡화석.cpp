#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<long long, int> m;

vector<long long> dinosaurs = {1000000005, 1000000006, 1000000035, 1000000002, 
                                1000000011, 1000000005, 1000000015, 1000000025};

int main() {

    for (auto dino : dinosaurs) {
        m[dino]++;
    }

    int age;
    cin >> age;

    cout << m[age] << "마리";

    return 0;
}