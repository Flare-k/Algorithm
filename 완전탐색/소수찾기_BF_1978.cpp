#include <iostream>
#include <math.h>
using namespace std;

int cnt = 0;

bool prime(int n) {
    int root = sqrt(n);
    if (n < 2)
        return false;
    else {
        for (int i = 2; i <= root; i++) {
            if (n % i == 0)
                return false;
        }
    }
    return true;
}

int main(){
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int random;
        cin >> random;

        if (prime(random))
            cnt++;
    }

    cout << cnt << '\n';
    
    return 0;
}
