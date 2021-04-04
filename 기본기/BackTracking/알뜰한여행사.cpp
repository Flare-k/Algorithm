#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    char from;
    char to;
    int value;
};
/*
B T 10
G T 3
G H 6
G K 2
H B 1
K B 8
T H 2
T B 4
*/
int vect[100];

vector<Node> list = {
    {'B', 'T', 10},
    {'G', 'T', 3},
    {'G', 'H', 6},
    {'G', 'K', 2},
    {'H', 'B', 1},
    {'K', 'B', 8},
    {'T', 'H', 2},
    {'T', 'B', 4}
};

vector<pair<char, int>> travel[8];
int minSum = 21e8;
bool visit[10][10];

void init() {
    travel['B'].push_back({'T', 10});
    travel['G'].push_back({'T', 3});
    travel['G'].push_back({'H', 6});
    travel['G'].push_back({'K', 2});
    travel['H'].push_back({'B', 1});
    travel['K'].push_back({'B', 8});
    travel['T'].push_back({'H', 2});
    travel['T'].push_back({'B', 4});
}

void DFS(char from, char to) {
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    char aFrom, aTo;
    cin >> aFrom >> aTo;



    return 0;
}