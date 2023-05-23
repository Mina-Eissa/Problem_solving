a, b = map(int, input().split())

if a > b:
    a, b = b, a
ctr = 0
while a > 0:
    ctr += b // a
    b %= a
    a, b = b, a
print(ctr - 1)
