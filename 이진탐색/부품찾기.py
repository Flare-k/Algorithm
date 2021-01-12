# -*- coding: utf-8 -*-
'''
전자 매장에는 부품이 N개가 있다. 각 부품은 정수 형태의 고유한 번호가 있다. 어느 날 손님이
M개 종류의 부품을 대량으로 구매하겠다며 당일 날 견적서를 요청했다. 동빈이는 때를 놓치지 않고 손님이
문의한 부품 M개 종류를 모두 확인해서 견적서를 작성해야 한다. 이때 가게 안에 부품이 모두 있는지 확인하는 프로그램을 작성해보자.

예를 들어 가게의 부품이 총 5개일 때 부품 번호가 다음과 같다고 하자.
N = 5
[8, 3, 7 ,9, 2]
손님은 총 3개의 부품이 있는지 확인 요청했는데 부품 번호는 다음과 같다.
M = 3
[5, 7 ,9]
'''

# 이진탐색 알고리즘


def binarySearch(partsN, target, start, end):
    while (start <= end):
        mid = (start+end)//2

        if (partsN[mid] == target):
            return mid
        elif (partsN[mid] > target):
            end = mid - 1
        else:
            start = mid + 1
    return None


N = int(input())  # 가게에 있는 부품 종류 개수
partsN = list(map(int, input().split()))  # 부품의 종류
partsN.sort()  # 이진탐색을 위한 정렬

M = int(input())  # 손님의 문의한 부품 종류 개수
partsM = list(map(int, input().split()))  # 부품의 종류


for target in partsM:
    result = binarySearch(partsN, target, 0, N-1)
    if result != None:  # 부품이 존재할 경우
        print("yes", end=' ')
    else:               # 부품이 존재하지 않을 경우
        print("no", end=' ')
