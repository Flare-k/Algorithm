#include <iostream>
using namespace std;
const int MAX = 1000000+1;
int arr[MAX];

void erathosthenes() {
    arr[0] = arr[1] = 0;

    for (int i = 2; i < MAX; i++) {
        arr[i] = i; //MAX만큼 배열에 모두 초기화 해준다.
    }
    
    for (int i = 2; i <= MAX; i++) {
        if (arr[i] == 0) continue;   //이미 체크된 수의 배수는 확인하지 않는다.
        for (int j = i + i; j <= MAX; j += i)    // i를 제외한 i의 배수들은 0으로 체크한다.
            arr[j] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    
    cin >> n >> m;
    
    erathosthenes();
    
    for (int i = n; i <= m; i++) {
        if (arr[i] != 0) cout << arr[i] << '\n';
    }
    
    return 0;
}
