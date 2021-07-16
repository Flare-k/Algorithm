#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const ll MAX = 2000001;

vector<int> sosu;
ll arr[MAX];

void run(){
    arr[0] = arr[1] = 0;
    
    for (ll i = 2; i < MAX; i++) {
        arr[i] = i;
    }
    
    for (ll i = 2; i < MAX; i++) {
        if(arr[i] != 0){
            for(ll j = i + i; j < MAX; j += i)
                arr[j] = 0;
            }
    }

    for (ll i = 2; i < MAX; i++) {
        if (arr[i] != 0) sosu.push_back(arr[i]);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    run();

    int t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;

        ll sum = a + b;

        if (sum == 2 || sum == 3) cout << "NO" << '\n';
        else if (sum % 2 == 0) cout << "YES" << '\n';
        else {
            bool flag = false;

            sum -= 2;

            for (int i = 0; i < sosu.size() && (ll)sosu[i] * sosu[i] <= sum; i++) {
                if (sum % sosu[i] == 0) {
                    cout << "NO" << '\n';
                    flag = true;
                    break;
                }
            }

            if (!flag) cout << "YES" << '\n';
        }
    }

    return 0;
}