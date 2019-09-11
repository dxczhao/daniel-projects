import re

f = open('new.txt')
text = f.read()

sentences = re.split(r'(?<!\w\.\w.)(?<![A-Z][a-z]\.)(?<=\.|\?)\s', text)
for stuff in sentences:
        print(stuff)
        print('new LINE')
