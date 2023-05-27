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


def valid(mid, v, n, k):
    lf = [0] * (n + 1)
    rt = [0] * (n + 2)
    sum_val = 0
    pq = []
    for i in range(n):
        heappush(pq, -v[i])
        sum_val += v[i]
        if sum_val > mid:
            sum_val -= -heappop(pq)
        lf[i + 1] = len(pq)
    while pq:
        heappop(pq)
    sum_val = 0
    for i in range(n - 1, -1, -1):
        heappush(pq, -v[i])
        sum_val += v[i]
        if sum_val > mid:
            sum_val -= -heappop(pq)
        rt[i + 1] = len(pq)
    for i in range(n):
        if lf[i] + rt[i + 1] >= k:
            return True
    return False


def solve():
    n, k = MI()
    v = LI()
    st = 1
    ed = int(1e18)
    ans = -1
    while st <= ed:
        mid = (st + ed) // 2
        if valid(mid, v, n, k):
            ans = mid
            ed = mid - 1
        else:
            st = mid + 1
    print(ans)

if __name__ == '__main__':
    t = II()
    for _ in range(t):
        solve()
