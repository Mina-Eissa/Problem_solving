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
}

void solve()
{
    string s;
    cin >> s;
    int last = '?';
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
            s[i] = last;
        last = s[i];
    }
    last = '?';
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '?')
            s[i] = last;
        last = s[i];
    }
    cout << (last == '?' ? string(s.size(), '0') : s) << "\n";
}

int main()
{
    fast();
    solve();

    return 0;
}
