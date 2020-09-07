# -*- coding: utf-8 -*-

'''
N가지 종류의 화폐가 있다. 이 화폐들의 개수를 최소한으로 이용해서 그 가치의 합이 M원이 되도록 하려고 한다.
이때 각 화폐는 몇 개라도 사용할 수 있으며, 사용한 화폐의 구성은 같지만 순서만 다른 것은 같은 경우로 구분한다.
예를 들어 2원, 3원 단위의 화폐가 있을 때는 15원을 만들기 위해 3원을 5개 사용하는 것이 가장 최소한의 화폐 개수이다.
2 15
2
3
> 5
'''
n, m = list(map(int, input().split()))
arr = []
for i in range(n):
    arr.append(int(input()))

dp = [10001]*(m+1)
dp[0] = 0

for i in range(n):
    for j in range(arr[i], m+1):
        if dp[j-arr[i]] != 10001:
            dp[j] = min(dp[j], dp[j-arr[i]]+1)

if dp[m] == 10001:
    print(-1)
else:
    print(dp[m])
