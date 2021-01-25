#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;   // 스크린 칸 수, 바구니 수
    cin >> n >> m;

    int num;    // 떨어지는 사과의 개수
    cin >> num;
    
    int idx = 1;
    int dist = 0;
    for (int i = 0; i < num; i++) {
        int apple;
        cin >> apple;

        while (1) {
            bool flag = false;

            for (int bucket = idx; bucket <= idx + (m - 1); bucket++) {
                if (bucket == apple) {
                    flag = true;
                    break;
                }
            }

            if (flag) 
                break;
            
            if (idx > apple)
                idx--;
            else
                idx++;
            
            dist++;
        }
    }

    cout << dist;
    return 0;
}