import re

text = input()
answer = re.sub('(a|e|i|o|u)p(a|e|i|o|u)', '\\1',text)
print(answer)