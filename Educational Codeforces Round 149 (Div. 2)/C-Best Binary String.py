import sys
from typing import List
import heapq


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
    s = list(SI())
    last = '0'
    for i in range(len(s)):
        if s[i] == '?':
            s[i] = last
        last = s[i]
    last = '?'
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '?':
            s[i] = last
        last = s[i]
    if last == '?':
        print('0' * len(s))
    else:
        for x in s:
            print(x, end="")
        print()


if __name__ == '__main__':
    t = II()
    for _ in range(t):
        solve()
