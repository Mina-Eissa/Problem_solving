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
}
bool valid(ll& mid, vector<int>& v, int& n, int& k) {
    vector<int>lf(n + 1, 0), rt(n + 2, 0);
    ll sum = 0;
    priority_queue<int>pq;
    for (int i = 0; i < n; i++) {
        pq.push(v[i]);
        sum += v[i];
        if (sum > mid)
            sum -= pq.top(), pq.pop();
        lf[i + 1] = pq.size();
    }
    while (!pq.empty())pq.pop();
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        pq.push(v[i]);
        sum += v[i];
        if (sum > mid)
            sum -= pq.top(), pq.pop();
        rt[i + 1] = pq.size();
    }

    for (int i = 0; i < n; i++) {
        if (lf[i] + rt[i + 1] >= k)
            return 1;
    }
    return 0;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for (auto& it : v)
        cin >> it;

    ll st = 1, ed = 1e18, ans = -1;
    while (st <= ed) {
        ll mid = (st + ed) >> 1;
        if (valid(mid, v, n, k))
            ans = mid, ed = mid - 1;
        else
            st = mid + 1;
    }
    cout << ans << "\n";
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        //cout << "Case " << tt << ": ";
        solve();
        /* if (tt < t)
             cout << "\n";*/
    }

    return 0;
}
