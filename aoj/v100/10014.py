import sys
while True:
    (h, w) = map(int, input().split());
    if h == 0 and w == 0:
        break
    for i in range(0, h):
        for j in range(0, w):
            if (i + j) % 2 == 0:
                print('#', end = '');
            else:
                print('.', end = '');
        print('');
    print('');
