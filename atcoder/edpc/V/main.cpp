#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

lli mod;
const int N = 1e5 + 5;
vector<int> g[N];

map<pair<int, int>, lli> memo;
lli rec1(int curr, int prev)
{
  const pair<int, int> key = make_pair(prev, curr);
  if (memo.count(key)) return memo[key];
  lli x = 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    (x *= rec1(next, curr) + 1) %= mod;
  }
  return memo[key] = x;
}

void rec2(int curr, int prev, lli p)
{
  memo[make_pair(curr, prev)] = p;

  vector<lli> pref = {1};
  each (next, g[curr]) {
    lli x = pref.empty() ? 1 : pref.back();
    x *= memo[make_pair(curr, next)] + 1;
    pref.push_back(x % mod);
  }
  reverse(g[curr].begin(), g[curr].end());

  vector<lli> suff = {1};
  each (next, g[curr]) {
    lli x = suff.empty() ? 1 : suff.back();
    x *= memo[make_pair(curr, next)] + 1;
    suff.push_back(x % mod);
  }
  reverse(g[curr].begin(), g[curr].end());
  reverse(suff.begin(), suff.end());

  for (int i = 0; i < g[curr].size(); ++i) {
    int next = g[curr][i];
    if (next == prev) continue;
    rec2(next, curr, (pref[i] * suff[i + 1]) % mod);
  }

  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n >> mod) {
    memo.clear();
    fill(g, g + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    rec1(0, 0);
    rec2(0, 0, 0);
    for (int i = 0; i < n; ++i) {
      lli x = 1;
      each (j, g[i]) (x *= memo[make_pair(i, j)] + 1) %= mod;
      cout << x << endl;
    }
    // break;
  }

  return 0;
}
