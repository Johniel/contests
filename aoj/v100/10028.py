import sys

n = int(input())
ms = list(map(int, input().split()))
ms.sort()
sep = 0
for m in ms:
    if sep == 1:
        print(" ", sep = "", end="")
    print(m, sep = "", end="")
    sep = 1
print("")
