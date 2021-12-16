#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 11;
int book[MAX];
bool check[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        memset(book, 0, sizeof(book));
        int N, M, cnt = 0;
        cin >> N >> M;

        for (int i = 1; i <= N; i++) {
            book[i] = i;
        }

        for (int i = 0; i < M; i++) {
            int s, e;
            cin >> s >> e;

            if (!check[book[s]] && book[s] <= e) {
                check[book[s]] = true;
                book[s]++;
                book[s+1] = book[s];

                cnt++;
            }
        }

        cout << cnt << '\n';

    }


    return 0;
}


/*
1
7 4
1 7
1 7
1 7
2 2
> 4
*/