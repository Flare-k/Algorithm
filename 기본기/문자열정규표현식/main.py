import re

# 출처: https://nachwon.github.io/regular-expressions/

# var = re.compile('정규표현식')

# [] : 대괄호 안에 포함된 문자들 중 하나와 매치
# [abc] = [a-c], [012345] = [0-5], [a-zA-Z] = 모든 알파벳
# ^는 반대를 의미함. [^0-9] = 숫자를 제외한 문자
# .은 줄바꿈 문자를 제외한 모든 문자 => [a.b] = a + ~~~ + b
# '문자'*은 반복되는 문자와 매치 => ab*c = ac, abbc, abbbbc, abbbbbbbbbbbc ...
# '문자'+은 반복되는 문자가 최소 한번 이상 매치 => ab+c = abbc, abbbbc, abbbbbbbbbbbc ...

v = re.compile('[a-z]+')

# match: 문자열 처음 시작부터 검색해 일치하지 않는 부분이 나올 때까지 탐색
print("-----------match-----------")
print("1. {}".format(v.match('aaa')))
print("2. {}".format(v.match('bbbbbbb')))
print("3. {}".format(v.match('1wqe')))
print("4. {}".format(v.match('abcda')))
print("5. {}".format(v.match('abc1da')))

# search: 전체 문자열에서 첫번째 매치 찾기
print("\n-----------search-----------")
print("1. {}".format(v.search('aaa')))
print("2. {}".format(v.search('bbbbbbb')))
print("3. {}".format(v.search('1weq')))
print("4. {}".format(v.search('abcda')))
print("5. {}".format(v.search('abc1da')))

# findall: 모든 매치를 찾아 리스트로 반환
print("\n-----------findall-----------")
print("1. {}".format(v.findall('aaa')))
print("2. {}".format(v.findall('bbbbbbb')))
print("3. {}".format(v.findall('1weq')))
print("4. {}".format(v.findall('abcda')))
print("5. {}".format(v.findall('abc1da')))

# finditer: 모든 매치를 찾아 반복가능 객체로 반환
print("\n-----------finditer-----------")
print("1. {}".format(v.finditer('aaa')))
obj = v.finditer('aaa')
for i in obj:
    print(i)


# group(): 매치된 문자열 출력
print("\n-----------group()-----------")
result = v.search('aaa')
print("group() result: {}".format(result.group()))

# start(): 매치 시작지점 인덱스 출력
print("\n-----------start()-----------")
result = v.search('aaa')
print("start() result: {}".format(result.start()))

# end(): 매치 끝지점 인덱스 출력
print("\n-----------end()-----------")
result = v.search('aaa')
print("end() result: {}".format(result.end()))

# span(): start(), end()를 튜플로 출력
print("\n-----------span()-----------")
result = v.search('aaa')
print("span() result: {}".format(result.span()))

# () 그룹화: 정규표현식을 () 안에 넣으면 그 부분만 그룹화 된다.
# groups()를 통해 그룹들을 튜플 형태로 리턴할 수 있다.
print("\n-----------groups()-----------")
result = re.search('(ls)(-[a-z])([^0-9]+)', 'ls-ahelloworld.cpp')
resultGroup = result.groups()
print("groups() result: {}".format(resultGroup))

result = re.search('(hello)(world)', 'helloworld')
resultGroup = result.groups()
print("groups() result: {}".format(resultGroup))


# 표현식1(?=표현식2): 표현식1 뒤의 문자열이 표현식2와 매치되면 표현식1 매치.
# 표현식1(?!표현식2): 표현식1 뒤의 문자열이 표현식2와 매치되지 않으면 표현식1 매치.
# (?<=표현식1)표현식2: 표현식2 앞의 문자열이 표현식1과 매치되면 표현식2 매치.
# (?<!표현식1)표현식2: 표현식2 앞의 문자열이 표현식1과 매치되지 않으면 표현식2 매치.

# 문자열 바꾸기
# sub 메서드를 사용하면 정규식과 매치되는 부분을 다른 문자로 쉽게 바꿀 수 있다.

p = re.compile('(blue|white|red)')
answer = p.sub('colour', 'blue socks and red shoes') #'colour socks and colour shoes'
print(answer)