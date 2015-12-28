import sys
n = input()
ns = input().split()
ns.reverse()
s = ""
for m in ns:
    s += m + " "
print(s[:-1])
