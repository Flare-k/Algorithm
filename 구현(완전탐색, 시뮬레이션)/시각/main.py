# H를 입력받기
h = int(input())

count = 0
for i in range(h + 1):
    for j in range(60):
        for k in range(60):
            # 매 시각 안에 '3'이 포함되어 있다면 카운트 증가
            if '3' in str(i) + str(j) + str(k):
                count += 1

print(count)

'''
c++에서는 boolean 함수를 따로 만들어야 했지만
파이썬은 문자열을 다루는데 비교적 쉽기 때문에 훨씬 코드가 간결하다.
'''
