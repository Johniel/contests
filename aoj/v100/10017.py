import sys
while True:
    (n, x) = map(int, input().split())
    if (n, x) == (0, 0): break;
    cnt = 0
    for a in range(1, n):
        for b in range(a + 1, n):
            c = x - a - b
            if b < c and c <= n:
                cnt += 1
    print(cnt)
