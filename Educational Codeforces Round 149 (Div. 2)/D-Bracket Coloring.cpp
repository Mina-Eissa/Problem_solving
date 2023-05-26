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
vector<int> fun(string &s, int &n)
{
    vector<int> idx;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            idx.push_back(i);
        }
        else
        {
            if (!idx.empty() && s[idx.back()] == '(')
                idx.pop_back();
            else
                idx.push_back(i);
        }
    }
    if (idx.size() % 2 != 0)
    {
        return vector<int>();
    }
    int p1 = 0, p2 = idx.size() - 1;
    while (p1 < p2)
    {
        swap(s[idx[p1++]], s[idx[p2--]]);
    }
    vector<int> ans(n, 1);
    for (auto it : idx)
        ans[it] = 2;
    idx.clear();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            idx.push_back(i);
        }
        else
        {
            if (!idx.empty() && s[idx.back()] == '(')
                idx.pop_back();
            else
                idx.push_back(i);
        }
    }
    if (!idx.empty())
    {
        return vector<int>();
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = s;
    reverse(all(s1));
    vector<int> ans1 = fun(s, n), ans2 = fun(s1, n);
    if (ans1.empty() && ans2.empty())
    {
        cout << -1 << "\n";
        return;
    }
    set<int> st(all(ans1)), st2(all(ans2));
    if (st.size() == 1 || st2.size() == 1)
    {
        cout << "1\n";
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
        cout << "\n";
    }
    else
    {
        cout << "2\n";
        for (auto it : ans1)
            cout << it << " ";
        cout << "\n";
    }
}

int main()
{
    fast();
    solve();
    return 0;
}
