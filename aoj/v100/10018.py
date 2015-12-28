import sys
s = input()
for c in s:
    if c.islower():
        print(c.upper(), end = "")
    else:
        print(c.lower(), end = "")
print("")
