import sys

while True:
    s = input()
    if s == "-":
        break
    n = int(input())
    while 0 <= n:
        n -= 1
        n = input()
        s = 