#include <iostream>
#include <algorithm>
#define MAX 2001
#define ll long long
using namespace std;

ll A[MAX];
int N;
ll answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A, A + N);

    for (int i = 0; i < N; i++) {
        int l = 0, r = N - 1, sum;

        while (l < r) {
            sum = A[l] + A[r];
            
            if(sum == A[i]){ 
                if(l != i && r != i){
                    answer++;
                    break;
                }
                else if (l == i) l++;
                else if (r == i) r--;
            }
            else if (sum < A[i]) l++;
            else r--;
        }
    }

    cout << answer << '\n';

    return 0;
}