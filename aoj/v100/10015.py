import sys
import itertools
n = int(input())
cs = list(itertools.product(['S', 'H', 'C', 'D'], range(1, 14)))
for i in range(1, n + 1):
    (c, n) = input().split()
    cs.remove((c, int(n)))
for c in cs:
    print(c[0], c[1])
