import sys

n = int(input())
ns = set(map(int, input().split()))

m = int(input())
ms = set(map(int, input().split()))

print(len(set.intersection(ns, ms)))
