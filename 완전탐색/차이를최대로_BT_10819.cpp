#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define endl "\n"
#define MAX 8
using namespace std;

int N, answer;
int Arr[MAX];
bool Select[MAX];
vector<int> V;

void Calculate() {
    int Sum = 0;
    for (int i = 0; i < V.size() - 1; i++) {
        Sum = Sum + abs(V[i] - V[i + 1]);
    }
    answer = max(answer, Sum);
}

void DFS(int Cnt) {
    if (Cnt == N) {
        Calculate();
        return;
    }

    for (int i = 0; i < N; i++) {
        if (Select[i] == true) continue;
        
        Select[i] = true;
        V.push_back(Arr[i]);
        DFS(Cnt + 1);
        Select[i] = false;
        V.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Arr[i];
    }
    DFS(0);
    cout << answer << endl;

    return 0;
}
