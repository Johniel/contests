import sys
import math
from functools import reduce

while True:
    n = int(input())
    if n == 0:
        break
    ss = list(map(float, input().split()))
    m = reduce(lambda a, b : a + b, ss, 0.0) / len(ss)
    a = math.sqrt(reduce(lambda a, b: a + b, map(lambda s : (s - m) * (s - m), ss), 0) / float(n))
    print(a)
