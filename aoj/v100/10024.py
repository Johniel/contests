import sys

while True:
    s = input()
    if s == "-":
        break
    q = int(input())
    l = len(s)
    while 0 < q:
        q -= 1
        n = int(input())
        s = s[n:] + s[0:n]
    print (s)
