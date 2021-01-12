# -*- coding: utf-8 -*-

'''
이진탐색 말고 계수정렬의 개념을 이용하여 풀이
'''
n = int(input())
array = [0]*1000000

for i in input().split():
    array[int(i)] = 1

m = int(input())
x = list(map(int, input().split()))

for i in x:
    if(array[i] == 1):
        print("yes", end=' ')
    else:
        print("no", end=' ')
