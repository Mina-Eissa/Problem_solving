import sys
from typing import List
import heapq


def LI(): return list(map(int, sys.stdin.readline().rstrip().split()))


def II(): return int(sys.stdin.readline())


def MI(): return map(int, sys.stdin.readline().rstrip().split())


def S(): return sys.stdin.readline().rstrip()


readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def solve():
    n = II()
    s = input()
    maxi, ctr = 0, 1
    for i in range(1, n):
        if s[i] != s[i - 1]:
            maxi = max(maxi, ctr)
            ctr = 1
        else:
            ctr += 1
    maxi = max(maxi, ctr)
    print(maxi + 1)


if __name__ == '__main__':
    t = II()
    for _ in range(t):
        solve()
