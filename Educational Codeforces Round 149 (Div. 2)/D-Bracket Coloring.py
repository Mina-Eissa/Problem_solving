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
def fun(s, n):
    idx = []
    for i in range(n):
        if s[i] == '(':
            idx.append(i)
        else:
            if idx and s[idx[-1]] == '(':
                idx.pop()
            else:
                idx.append(i)
    if len(idx) % 2 != 0:
        return []
    p1, p2 = 0, len(idx) - 1
    while p1 < p2:
        s[idx[p1]], s[idx[p2]] = s[idx[p2]], s[idx[p1]]
        p1 += 1
        p2 -= 1
    ans = [1] * n
    for it in idx:
        ans[it] = 2
    idx.clear()
    for i in range(n):
        if s[i] == '(':
            idx.append(i)
        else:
            if idx and s[idx[-1]] == '(':
                idx.pop()
            else:
                idx.append(i)
    if idx:
        return []
    return ans
def solve():
    n = II()
    s = list(SI())
    s1 = s[::-1]
    ans1 = fun(list(s), n)
    ans2 = fun(list(s1), n)
    if not ans1 and not ans2:
        print(-1)
        return
    st = set(ans1)
    st2 = set(ans2)
    if len(st) == 1 or len(st2) == 1:
        print(1)
        for i in range(n):
            print(1, end=' ')
        print()
    else:
        print(2)
        for it in ans1:
            print(it, end=' ')
        print()


if __name__ == '__main__':
    t = II()
    for _ in range(t):
        solve()
