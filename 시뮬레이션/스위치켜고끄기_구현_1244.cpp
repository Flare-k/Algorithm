#include <iostream>
#include <vector>
using namespace std;

// 남학생 = 받은 수의 배수 상태 변경
// 여학생 = 받은 수를 중심으로 좌우 중 가장 많은 스위치(on)를 포함하는 구간에 속한 스위치 상태 변경

enum {
    G, MALE, FEMALE
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<bool> switches;
    switches.push_back(0);

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        switches.push_back(s);
    }

    int students;
    cin >> students;

    for (int i = 0; i < students; i++) {
        int gender, num;
        cin >> gender >> num;

        if (gender == MALE) {
            for (int i = num; i < switches.size(); i += num) {
                switches[i] = !switches[i];
            }
        }
        else if (gender == FEMALE) {
            int s = num - 1;
            int e = num + 1;

            while ((s > 0 && e <= n) && switches[s] == switches[e]) {
                switches[s] = !switches[s];
                switches[e] = !switches[e];
                
                s--;
                e++;
            }

            switches[num] = !switches[num];
        }
    }

    for (int i = 1; i < switches.size(); i++) {
        cout << switches[i] << ' ';
        if (i % 20 == 0) cout << '\n';
    }

    return 0;
}