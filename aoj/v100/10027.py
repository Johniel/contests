import sys

n = int(input())
a = 0;
b = 0;
for i in range(0, n):
    (s, t) = input().split()
    if s == t:
        a += 1
        b += 1
    elif s > t:
        a += 3
    else:
        b += 3
print(a, b)