#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> classes;
int mgt, sub;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    classes.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> classes[i];
    }

    cin >> mgt >> sub;

    long long cnt = N;

    for (int i = 0; i < N; i++) {
        classes[i] -= mgt;
        
        if (classes[i] <= 0) continue;

        if (classes[i] < sub) cnt++;
        else if (classes[i] % sub == 0) cnt += (classes[i] / sub);
        else cnt += (classes[i] / sub + 1);
    }

    cout << cnt;

    return 0;
}