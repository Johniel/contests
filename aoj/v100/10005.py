l = []
while True:
    n = int(input())
    if n == 0: break;
    l.append(n)
for (a, b) in zip(range(1, len(l) + 1), l):
    print("Case {}: {}".format(a, b));
