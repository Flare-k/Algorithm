#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   priority_queue<int> train;

   int sum = 0;

   for (int i = 0; i < 10; i++) {
        int out, in;
        cin >> out >> in;

        sum -= out;
        sum += in;

        train.push(sum);
    }

    cout << train.top();

    return 0;
}