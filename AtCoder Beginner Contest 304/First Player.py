import collections
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


def solve():
    n = II()
    a, b = [], []
    for i in range(n):
        x, y = input().split()
        y = int(y)
        a.append([y, x, i])
        b.append([y, x, i])

    b.sort()
    j = (b[0][2] + 1) % n
    print(b[0][1])
    while j != b[0][2]:
        print(a[j][1])
        j = (j + 1) % n


if __name__ == '__main__':
    t = 1  # II()
    for _ in range(t):
        solve()
