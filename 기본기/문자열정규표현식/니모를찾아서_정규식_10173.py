import re

while True:
    text = input()
    if text == "EOI":
        break
    
    p = re.findall('nemo', text.lower())
    if len(p) != 0:
        print("Found")
    else:
        print("Missing")
