
binary = input().split()
tmp = []

for bin in binary :
    bin = bin[::-1]
    
    length = len(bin)

    x = 1
    ans = 0
    idx = 0

    while length:
        ans += (x * int(bin[idx]))
        idx += 1
        x *= 2
        length -= 1

    tmp.append(ans)

target = sum(tmp)


if target == 0:
    print(0)
else :
    res = ""
    while target != 0:
        res += str(target % 2)
        target //= 2
    
    res = res[::-1]
    print(res)
