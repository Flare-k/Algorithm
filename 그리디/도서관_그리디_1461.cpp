#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, amount;
    cin >> n >> amount;

    vector<int> posBooks;   // 책이 양수의 위치에 있는 경우
    vector<int> negBooks;   // 책이 음수의 위치에 있는 경우

    int book;
    for (int i = 0; i < n ; i++) {
        cin >> book;
        
        if (book < 0) negBooks.push_back(-book);
        else posBooks.push_back(book);
    }

    // 음수/양수 모두 거리가 먼 순서부터 내림차순 정렬
    if (!negBooks.empty()) sort(negBooks.begin(), negBooks.end(), greater<int>());
    if (!posBooks.empty()) sort(posBooks.begin(), posBooks.end(), greater<int>());

    int res = 0;

    // 들 수 있는 책의 개수만큼 x2
    for (int i = 0; i < posBooks.size(); i += amount) {
        res += (posBooks[i] * 2);
    }

    for (int i = 0; i < negBooks.size(); i += amount) {
        res += (negBooks[i] * 2);
    }

    // 만약 음수의 경우 책이 없었다면 양수에서 책을 다 나눠주고 그자리에서 끝나야 하므로..
    if (negBooks.empty()) {
        res -= posBooks[0];
    }
    else if (posBooks.empty()) {
        res -= negBooks[0];
    }
    // 만약 양수가 제일 멀다면 가장 마지막에 가야한다. 따라서 x2했을 때에서 하나를 빼준다.
    else if (negBooks[0] < posBooks[0]) {
        res -= posBooks[0];
    }
    else {
        res -= negBooks[0];
    }

    cout << res;

    return 0;
}