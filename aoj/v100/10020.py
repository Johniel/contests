import sys
import string

s = ""
for t in sys.stdin:
    s += t.lower()

for c in string.ascii_lowercase:
    print(c, ":", s.count(c))
