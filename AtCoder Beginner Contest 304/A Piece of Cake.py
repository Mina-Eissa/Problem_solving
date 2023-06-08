import bisect
from collections import deque
import math
import sys
from typing import List
from heapq import *


def LI(): return list(map(int, sys.stdin.readline().rstrip().split()))


def II(): return int(sys.stdin.readline())


def MI(): return map(int, sys.stdin.readline().rstrip().split())


def S(): return sys.stdin.readline().rstrip()


def SI(): return sys.stdin.readline().strip()


def MIN_INT(): return -1 * sys.maxsize


def MAX_INT(): return sys.maxsize


readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def dis(a, b):
    x = a[0] - b[0]
    y = a[1] - b[1]
    return math.sqrt(x * x + y * y)


def solve():
    w, h = MI()
    n = II()
    strw = []
    for _ in range(n):
        x, y = MI()
        strw.append([x, y])
    a1 = II()
    a = LI()
    b1 = II()
    b = LI()

    a.append(w)
    b.append(h)

    mp = {}
    for it in strw:
        x = bisect.bisect_left(a, it[0])
        y = bisect.bisect_left(b, it[1])
        mp[(x, y)] = mp.get((x, y), 0) + 1

    mini = MAX_INT()
    maxi = MIN_INT()
    for it in mp.values():
        mini = min(mini, it)
        maxi = max(maxi, it)

    if not mp:
        mini = maxi = 0
    elif len(mp) < (a1 + 1) * (b1 + 1):
        mini = 0

    print(mini, maxi)


if __name__ == '__main__':
    t = 1  # II()
    for _ in range(t):
        solve()
