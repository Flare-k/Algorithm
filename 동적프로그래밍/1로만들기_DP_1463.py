# -*- coding: utf-8 -*-
'''
 * x가 5로 나누어 떨어지면, 5로 나눈다.
 * x가 3으로 나누어 떨어지면, 3으로 나눈다.
 * x가 2로 나누어 떨어지면, 2로 나눈다.
 * x에서 1을 뺀다.
'''

x = int(input())

d = [0]*30001

for i in range(2, x+1):
    d[i] = d[i-1]+1

    if i % 2 == 0:
        d[i] = min(d[i], d[i//2]+1)
    if i % 3 == 0:
        d[i] = min(d[i], d[i//3]+1)
    if i % 5 == 0:
        d[i] = min(d[i], d[i//5]+1)
print(d[x])
