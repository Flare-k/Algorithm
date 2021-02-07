#include <iostream>
#include <vector>

using namespace std;


/**
 * 순열은 순서를 고려해야 한다.
 * 즉, 과거 시작점을 다시 한 번 생각해봐야 한다.
 * 조합의 경우 {1, 2, 3}과 {2, 1, 3}은 서로 같은 의미지만 순열은 다른 의미이다.
*/

const int MAX = 5;

int arr[MAX];
bool select[MAX];
vector<int> v;

void printAns() {
    for (int num : v) {
        cout << num << " ";
    } 
    cout << '\n';
}

// 시작점을 다시 한 번 쳐다봐야 하기 때문에 조합과 달리 시작점을 결정해주는 idx 매개변수가 필요하지 않다.
void permutation(int pick, int cnt) {
    if (cnt == pick) {
        printAns();
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (select[i]) continue;

        select[i] = true;
        v.push_back(arr[i]);
        permutation(pick, cnt + 1);
        v.pop_back();
        select[i] = false;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, pick;
    cout << "최대값: ";
    cin >> n;
    cout << "몇 개의 수를 뽑을 것인가? ";
    cin >> pick;

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    permutation(pick, 0);

    return 0;
}