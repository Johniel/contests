import sys
import string

n = int(input())
mn = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
while 0 < n:
    n -= 1
    s = input()
    mn = min(mn, s)
print(mn)