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


class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.depth = [1] * (n + 1)
        self.forests = n

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def link(self, x, y):
        if self.depth[x] > self.depth[y]:
            x, y = y, x
        self.parent[x] = y
        if self.depth[x] == self.depth[y]:
            self.depth[y] += 1

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x != y:
            self.link(x, y)
            self.forests -= 1
        return x != y

def solve():
    n, m = MI()
    d = DSU(n)
    for _ in range(m):
        u, v = MI()
        d.union(u, v)

    no = set()
    k = II()
    for _ in range(k):
        u, v = MI()
        x = d.find(u)
        y = d.find(v)
        if x > y:
            x, y = y, x
        no.add((x, y))

    q = II()
    for _ in range(q):
        u, v = MI()
        x = d.find(u)
        y = d.find(v)
        if x > y:
            x, y = y, x
        if (x, y) in no:
            print("No")
        else:
            print("Yes")


if __name__ == '__main__':
    t = 1  # II()
    for _ in range(t):
        solve()
