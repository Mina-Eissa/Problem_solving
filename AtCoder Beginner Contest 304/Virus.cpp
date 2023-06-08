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
double dis(vector<int>& a, vector<int>& b)
{
    double x = a[0] - b[0];
    double y = a[1] - b[1];
    return sqrt(x * x + y * y);
}
void solve()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>>a(n, vector<int>(2));
    for (auto& it : a)
        cin >> it[0] >> it[1];
    vector<vector<int>>adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (dis(a[i], a[j]) <= d)
                adj[i].push_back(j);
        }
    }
    vector<bool>vis(n, 0);
    vis[0] = 1;
    queue<int>q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto it : adj[cur]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    for (auto it : vis) {
        cout << (it ? "Yes" : "No") << "\n";
    }

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
