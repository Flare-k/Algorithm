import re

p = re.compile('(100+1+|01)+')

T = int(input())

for i in range(T):
    text = input()
    answer = p.fullmatch(text)

    if answer:
        print("YES")
    else:
        print("NO")
