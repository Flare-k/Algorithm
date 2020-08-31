# -*- coding: utf-8 -*-

'''
이 문제는 M이 10,000 이하이므로 main.py 처럼 풀 수 있지만, M의 크기가 100억 이상처럼 커진다면 시간 초과 판정을 받을 것이다.

반복되는 수열에 대해서 파악해야 한다.

ex, N: 배열의 길이,  M: 연산의 횟수,  K: 중복해서 더할 수 있는 횟수.
N =5, M=8, K=3
 6 + 6 + 6 + 5 | 6 + 6 + 6 + 5
반복되는 수열의 길이는 어떻게 될까? 
M을 (K+1)로 나눈 몫이 수열이 반복되는 횟수가 된다. 여기에 K를 곱해주면 가장 큰 수가 등장하는 횟수가 된다.
--> M/(K+1) * K    == 8/(3+1) * 3 == 6

이때 M이 (K+1)로 나누어 떨어지지 않는 경우도 고려해야 한다. 그럴 떄는 M을 (K+1)로 나눈 나머지만큼
가장 큰 수가 추가로 더해지므로 이를 고려해주어야 한다.

<가장 큰 수가 더해지는 횟수>
> int(M/(K+1)) * K + M%(K+1)

'''

# N, M, K를 공백으로 구분하여 입력받기
n, m, k = map(int, input().split())
# N개의 수를 공백으로 구분하여 입력받기
data = list(map(int, input().split()))

data.sort()  # 입력 받은 수들 정렬하기
first = data[n-1]
second = data[n-2]

count = int(m/(k+1)) * k
count += m % (k+1)

result = 0
result += (count) * first
result += (m-count)*second

print(result)
