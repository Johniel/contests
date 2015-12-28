n = list(map((lambda x : int(x)), input().split(" ")))
n.sort()
s = ""
for m in n:
    if len(s) == 0:
        s = str(m)
    else:
        s = s + " " + str(m)
print(s)
