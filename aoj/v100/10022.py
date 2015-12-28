import sys

cnt = 0
w = input()
while True:
    s = input()
    if s == "END_OF_TEXT":
        break
    cnt += list(map(lambda t : t.lower(), s.split())).count(w)
print(cnt)
