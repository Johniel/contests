// atcoder/abc133/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

int color;
const int N = 1e5 + 5;
vector<int> g[N];

const lli mod = 1e9 + 7;

lli fact[N];

lli rec(int curr, int prev, lli p)
{
  // cout << curr+1 << ' ' << p << endl;

  lli x = p;
  lli q = color - (bool)curr - 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    x *= (rec(next, curr, q)) % mod;
    x %= mod;
    --q;
  }
  return x;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = 1;
  for (lli i = 1; i < N; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
  }

  int n;
  while (cin >> n >> color) {
    fill(g, g + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    cout << rec(0, 0, color) << endl;
    // cout << endl;
  }

  return 0;
}
