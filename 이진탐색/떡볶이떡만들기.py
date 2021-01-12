# -*- coding: utf-8 -*-
'''
동빈이네 떡볶이 떡은 재밌게도 떡의 길이가 일정하지 않다. 대신에 한 봉지 안에 들어가는 떡의 총 길이는 절단기로 잘라서 맞춰준다.
절단기에 높이(H)를 지정하면 줄지어진 떡을 한 번에 절단한다. 높이가 H보다 긴 떡은 H 위의 부분이 잘릴 것이고, 낮은 떡은 잘리지 않는다.
예를 들어 높이가 19, 14, 10, 17cm인 떡이 나란히 있고 절단기 높이를 15cm로 지정하면 자른 뒤 떡의 높이는 15, 14, 10, 15cm가 될 것이다.
잘린 떡의 길이는 차례대로 4, 0, 0, 2cm이다. 손님은 6cm만큼의 길이를 가져간다.
'''
# 떡의 개수 n과 요청한 떡의 길이 m을 입력받는다.
n, m = list(map(int, input().split()))
# 각 떡의 개별 높이 정보를 입력받는다.
arr = list(map(int, input().split()))

start = 0
end = max(arr)

result = 0

while(start <= end):
    sum = 0
    mid = (start+end)//2

    for dduck in arr:
        # 잘랐을 때의 떡의 양 계산
        if dduck > mid:
            sum += dduck - mid
    # 떡의 양이 부족한 경우 더 많이 자르기(왼쪽 부분 탐색)
    if sum < m:
        end = mid-1
    # 떡의 양이 충분한 경우 덜 자르기(오른쪽 부분 탐색)
    else:
        result = mid
        start = mid+1

print(result)
