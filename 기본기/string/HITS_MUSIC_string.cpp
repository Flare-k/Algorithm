#include <iostream>
#include <string>
using namespace std;

int main() {

    int n;
    cin >> n;

    string bucket[n];

    for (int i = 0; i < n; i++) {
        cin >> bucket[i];
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bucket[i] + bucket[j] == "HITSMUSIC")
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}