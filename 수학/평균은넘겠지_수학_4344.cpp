#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        float num;
        float sum = 0;
        vector<float> score;

        cin >> num;

        for (int j = 0; j < num; j++) {
            float subject;
            cin >> subject;

            score.push_back(subject);
            sum += subject;
        }

        int avg = 0;
        int cnt = 0;
        avg = sum / num;
        sort(score.begin(), score.end(), greater<int>());
        
        for (int i = 0; i < num; i++) {
            if (score[i] > avg)
                cnt++;
            else
                break;
        }
        
        cout << fixed;
        cout.precision(3);
        cout << cnt / num * 100 << "%" << endl;
    }
    return 0;
}
