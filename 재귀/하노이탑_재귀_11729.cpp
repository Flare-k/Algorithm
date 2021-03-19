#include <iostream>
#include <utility>
#include <vector>

#define endl "\n"

using namespace std;

int cnt = 0;
vector<pair<int, int> > ans;

void honoiTop(int num, int from, int by, int to) {
    cnt++;
    if (num == 1) {
        ans.push_back(make_pair(from, to));
    } 
    else {
        honoiTop(num - 1, from, to, by);  // n-1개의 원판을 1번에서부터(from) 3번을 거쳐(by) 2번으로(to) 가게한다.
        ans.push_back(make_pair(from, to));
        honoiTop(num - 1, by, from, to); //  그런다음 2번에 있는 원판을(from) 1번을 거쳐(by) 3번으로(to) 마무리한다.
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int n;
    cin >> n;

    honoiTop(n, 1, 2, 3);

    cout << cnt << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}