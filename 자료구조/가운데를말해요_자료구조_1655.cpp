#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
1. 최대힙의 크기는 항상 최소힙의 크기보다 같거나 '1'만큼 더 크다.
2. 최소힙의 모든 원소는 최대힙의 모든 원소보다 항상 크거나 같아야 한다.
    즉, 최소힙의 가장 top() 값은 항상 최대힙의 가장 top() 값 보다 크거나 같아야 한다.
*/

int N, num;
priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int cnt = 0;
    while (N--) {
        cin >> num;
        
        if (maxpq.size() > minpq.size()) minpq.push(num);
        else maxpq.push(num);

        if (!maxpq.empty() && !minpq.empty()) {
            if (maxpq.top() > minpq.top()) {
                int maxx = maxpq.top();
                int minn = minpq.top();

                maxpq.pop();
                minpq.pop();

                maxpq.push(minn);
                minpq.push(maxx);
            }
        }

        cout << maxpq.top() << '\n';
    }

    return 0;
}