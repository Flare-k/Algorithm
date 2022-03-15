import re

S = input()
result = re.compile('<[\w ]+>|[\w ]+')
re_list = result.findall(S)

str = str()

for r in re_list:
    tmp = list()

    if r[0] != '<':
        if r.find(' '):
            tmp = r.split()

    if len(tmp) > 0:
        for t in tmp:
            str += t[::-1] + ' '
        str = str[:-1]
    else:
        str += r

print(str)