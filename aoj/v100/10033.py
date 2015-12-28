import sys

n = int(input())
stack = []
for x in range(0, n + 1):
    stack.append([])

while True:
    s = input()
    if s == "quit":
        break
    ss = s.split()
    if ss[0] == "pop":
        print(stack[int(ss[1])].pop())
    elif ss[0] == "move":
        src = int(ss[1])
        dst = int(ss[2])
        stack[dst].append(stack[src].pop())
    else:
        stack[int(ss[1])].append(ss[2])