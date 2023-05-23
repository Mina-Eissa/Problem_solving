s = input()
B1, B2, R1, R2, K = -1, -1, -1, -1, -1
for i in range(len(s)):
    if s[i] == 'B':
        if B1 == -1:
            B1 = i
        else:
            B2 = i
    elif s[i] == 'R':
        if R1 == -1:
            R1 = i
        else:
            R2 = i
    elif s[i] == 'K':
        K = i

print("Yes" if (B2-B1)%2!=0 and K>R1 and K<R2 else "No")