n, w = map(int, input().split())
v = []
for i in range(n):
    v.append(input())
s = '\n'.join(v)

print(s.replace('TT', 'PC'))
