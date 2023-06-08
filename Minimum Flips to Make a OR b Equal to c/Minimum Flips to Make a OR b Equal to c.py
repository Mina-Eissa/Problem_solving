class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        ctr = 0
        while c != 0 or a != 0 or b != 0:
            if c % 2 != 0:
                ctr += 1 if (a%2==0) and (b%2==0) else 0
            else:
                ctr += 1 if a%2!=0 else 0
                ctr += 1 if b%2!=0 else 0
            a//=2
            b//=2
            c//=2
        return ctr