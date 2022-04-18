#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define MAX 101
using namespace std;

int N1, N2;
int T;
string ant1, ant2;
int arr[MAX * MAX];
struct Node {
    int s, e;
};
vector<Node> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N1 >> N2;
    cin >> ant1 >> ant2;
    cin >> T;

    reverse(ant1.begin(), ant1.end());

    string ants = ant1 + ant2;

    for (int i = 0; i < N1; i++) {
        arr[i] = 1;
    }

    for (int i = N1; i < N1 + N2; i++) {
        arr[i] = 2;
    }

    while (T--) {
        vec.clear();

        for (int i = 0; i < N1 + N2 - 1; i++) {
            if (arr[i] == 1 && arr[i + 1] == 2) {
                vec.push_back({i, i + 1});
            }
        }

        for (auto v : vec) {
            swap(arr[v.s], arr[v.e]);
            swap(ants[v.s], ants[v.e]);
        }
    }

    cout << ants << '\n';

	return 0;
}