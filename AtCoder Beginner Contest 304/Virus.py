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
    n, d = MI()
    a = []
    for i in range(n):
        x, y = MI()
        a.append([x, y])
    adj = [[] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            if (dis(a[i], a[j]) <= d):
                adj[i].append(j)
    vis = [False]*n
    q = deque()
    vis[0]=True
    q.append(0)
    while q:
        cur = q.popleft()
        for x in adj[cur]:
            if not vis[x]:
                q.append(x)
                vis[x] = True

    for x in vis:
        print("Yes" if x else "No")


if __name__ == '__main__':
    t = 1  # II()
    for _ in range(t):
        solve()
