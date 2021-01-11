/*
//  main.cpp
//  일곱난쟁이_BF_2309
 
 아홉 명 중에 일곱 명을 고르는 것은 아홉 명 중에 두 명을 고르는 것과 같다.
 <경우의 수 계산>
 코드로 Combination을 표현하긴 힘듬..
 난쟁이의 수를 n이라고 했을 때
 두 명을 고르는 경우의 수 = 9C2 = nC2 = n(n-1)/2 = O(n^2)
 나머지 난쟁이의 키(일곱 명)의 합을 고르는 시간 복잡도: O(n-2) = O(n)
 O(n^2):방법의개수 x O(n):값 = O(n^3)   , n=9이므로 O(n^3)은 충분히 1초안에 풀 수 있다.
 
 아래 코드는 O(n^2)이다. 제일 안에 있는 for문은 정답을 찾았을때 한번만 실행되게 때문이다.
 */

#include <iostream>
#include <algorithm>
using namespace std;

int hobit[9];
int n = 9;

int main() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> hobit[i];
        sum += hobit[i];
    }

    sort(hobit, hobit + n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sum - hobit[i] - hobit[j] == 100) {
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) 
                        continue;
                    cout << hobit[k] << '\n';
                }
                
                return 0;
            }
        }
    }
    
    return 0;
}
