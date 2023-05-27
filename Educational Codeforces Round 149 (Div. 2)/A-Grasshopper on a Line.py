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
    n, m = MI()
    if n % m == 0:
        print('2\n' + str(n - 1) + ' ' + '1')
    else:
        print(f'1\n{n}')


if __name__ == '__main__':
    t = II()
    for _ in range(t):
        solve()
