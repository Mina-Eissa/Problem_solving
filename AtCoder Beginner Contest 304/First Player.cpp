/*
 ####  ####  ####
 ## ##  ##  ## ##
 ##  ## ## ##  ##
 ##   ######   ##
 ##     ## ######
 ###   ####   ###
*/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define MOD1 1000000007
#define MOD2 998244353
#define pi acos(-1)
#define ull unsigned long long
#define ll long long
#define all(s) s.begin(), s.end()
#define allr(s) s.rbegin(), s.rend()
#define OO 1000000000
#define mp(x, y) make_pair(x, y)
using namespace std;
long long Mod(long long num, long long mod) { return ((num % mod) + mod) % mod; }
long long Ceil(long long num, long long div) { return (num + div - 1) / div; }
long long Gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return Gcd(b % a, a);
}
long long Lcm(long long a, long long b) { return a / Gcd(a, b) * b; }
int quadform(long long n) { return (ceil(sqrt((8 * n)) + 1) - 1) / 2; }
const int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

void fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<pair<int, string>, int>> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first.second >> a[i].first.first;
        a[i].second = i;
    }
    b = a;
    sort(all(b));
    int j = (b[0].second + 1) % n;
    cout << b[0].first.second << "\n";
    for (j; j != b[0].second; j = (j + 1) % n)
        cout << a[j].first.second << "\n";
}

int main()
{
    fast();
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        // cout << "Case " << tt << ": ";
        solve();
        /* if (tt < t)
             cout << "\n";*/
    }

    return 0;
}
