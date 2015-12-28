import sys

stack = []
while True:
    q = input()
    if q == "quit":
        break
    if q == "pop":
        print(stack.pop())
    else:
        (s, t) = q.split()
        stack.append(t)