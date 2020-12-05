# -*- coding: utf-8 -*-
x = int(input())
arr = list(map(int, input().split()))
# 1 3 1 5
dp = [0]*30001
dp[0] = arr[0]  # 1
dp[1] = max(arr[0], arr[1])  # 3

for i in range(2, x):
    dp[i] = max(dp[i-1], dp[i-2]+arr[i])

print(dp[x-1])
