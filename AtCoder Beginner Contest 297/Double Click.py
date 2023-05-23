n, d = map(int, input().split())
v = list(map(int, input().split()))
ok = -1
for i in range(n):
    for j in range(i + 1, n):
        if v[j] - v[i] <= d:
            ok = v[j]
            break
    if ok != -1:
        break
print(str(ok))
