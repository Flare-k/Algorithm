# -*- coding: utf-8 -*-

'''
이진탐색 말고 set(집합)의 개념을 이용하여 풀이
'''
n = int(input())
array = set(map(int, input().split()))

m = int(input())
x = list(map(int, input().split()))

for i in x:
    if i in array:
        print("yes", end=' ')
    else:
        print("no", end=' ')
