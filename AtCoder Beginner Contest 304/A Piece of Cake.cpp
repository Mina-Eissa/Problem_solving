/*
 ####  ####  ####
 ## ##  ##  ## ##
 ##  ## ## ##  ##
 ##   ######   ##
 ##     ## ######
 ###   ####   ###
*/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define MOD1 1000000007
#define MOD2 998244353
#define pi acos(-1)
#define ull unsigned long long
#define ll long long
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(),s.rend()
#define OO 1000000000
#define mp(x,y) make_pair(x,y)
using namespace std;
long long Mod(long long num, long long mod) { return ((num % mod) + mod) % mod; }
long long Ceil(long long num, long long div) { return (num + div - 1) / div; }
long long Gcd(long long a, long long b) { if (a == 0)return b; return Gcd(b % a, a); }
long long Lcm(long long a, long long b) { return a / Gcd(a, b) * b; }
int quadform(long long n) { return (ceil(sqrt((8 * n)) + 1) - 1) / 2; }
const int dx[] = { -1,0,1,0,-1,1,-1,1 };
const int dy[] = { 0,1,0,-1,-1,1,1,-1 };

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
    int n, w, h;
    cin >> w >> h;
    cin >> n;
    vector<vector<int>>v;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({ x,y });
    }
    int a1, b1;
    cin >> a1;
    vector<int>a(a1);
    for (auto& it : a)
        cin >> it;
    cin >> b1;
    vector<int>b(b1);
    for (auto& it : b)
        cin >> it;

    a.push_back(w);
    b.push_back(h);

    map<vector<int>, int>mp;
    for (auto it : v) {
        x = lower_bound(all(a), it[0]) - a.begin();
        y = lower_bound(all(b), it[1]) - b.begin();
        mp[{x, y}]++;
    }
    int mini = INT_MAX, maxi = INT_MIN;
    for (auto it : mp)
        mini = min(mini, it.second), maxi = max(maxi, it.second);
    if (mp.empty())
        mini = maxi = 0;
    else if (mp.size() < (a1 + 1) * 1LL * (b1 + 1))
        mini = 0;

    cout << mini << " " << maxi;
}

int main() {
    fast();
    int t = 1;
    //cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        //cout << "Case " << tt << ": ";
        solve();
        /* if (tt < t)
             cout << "\n";*/
    }

    return 0;
}
