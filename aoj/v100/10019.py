import sys
while True:
    s = input()
    if s == "0":
        break
    n = 0
    for c in s:
        n += int(c)
    print(n)
