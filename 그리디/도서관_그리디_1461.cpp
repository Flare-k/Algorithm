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

    vector<int> books(n);

    int negative = 0;
    int positive = 0;

    for (int i = 0; i < n ; i++) {
        cin >> books[i];
        
        if (books[i] < 0) negative++;
        else positive++;
    }

    books.push_back(0);
    sort(books.begin(), books.end());

    int startIdx;
    for (int i = 0; i < books.size(); i++) {
        if (books[i] == 0) {
            startIdx = i;
            break;
        }
    }

    // 작은 쪽 먼저 확인

    if (negative > positive) {
        int left = startIdx + 1; 
        int right = books.size() - 1;
        int dist = 0;

        while (right <= startIdx) {
            dist += (books[right] * 2);
            right -= amount;
        }

        while (left >= startIdx) {

        }
    }
    else {
        int left = 0; 
        int right = startIdx + 1;
        int dist = 0;
        

    }



    return 0;
}