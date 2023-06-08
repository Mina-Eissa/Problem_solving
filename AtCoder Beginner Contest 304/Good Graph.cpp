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
struct DSU {
	vector<int>parent, depth;
	int forests = 0;
	DSU(int n) {
		parent = depth = vector<int>(n + 1);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			depth[i] = 1;
			forests++;
		}
	}
	int Find(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = Find(parent[x]);
	}
	void Link(int x, int y) {
		if (depth[x] > depth[y])
			swap(x, y);
		parent[x] = y;
		if (depth[x] == depth[y])
			depth[y]++;
	}
	bool Union(int x, int y) {
		x = Find(x), y = Find(y);
		if (x != y) {
			Link(x, y);
			forests--;
		}
		return x != y;
	}
};
void solve()
{
	int n, m;
	cin >> n >> m;
	DSU d(n);
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		d.Union(u, v);
	}
	set<vector<int>>no;
	int k;
	cin >> k;
	int ok = 1;
	for (int i = 0; i < k; i++) {
		cin >> u >> v;
		int x = d.Find(u), y = d.Find(v);

		if (x > y)
			swap(x, y);
		no.insert({ x,y });

	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> u >> v;
		int x = d.Find(u), y = d.Find(v);
		if (x > y)
			swap(x, y);
		cout << (no.find({ x,y }) != no.end() ? "No" : "Yes") << "\n";
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
