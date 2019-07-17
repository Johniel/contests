// atcoder/tdpc/N/main.cpp
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

const int N = 1000 + 5;
vector<int> g[N];

const lli mod = 1e9 + 7;
lli nck[N][N];

pair<lli, int> memo[N][N];
pair<lli, int> rec(int curr, int prev)
{
  pair<lli, int>& ret = memo[curr][prev];
  if (ret.second != -1) return ret;

  vector<pair<lli, int>> v;
  each (next, g[curr]) {
    if (next == prev) continue;
    v.push_back(rec(next, curr));
  }

  lli x = v.size();
  each (i, v) x += i.second;
  ret.second = x;

  lli y = 1;
  each (i, v) {
    (y *= i.first) %= mod;
    (y *= nck[x][i.second + 1]) %= mod;
    x -= i.second + 1;
  }

  ret.first = y;
  return ret;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fill(&nck[0][0], &nck[N - 1][N - 1] + 1, 0);
  for (int i = 0; i < N; ++i) {
    nck[i][i] = nck[i][0] = 1;
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      nck[i][j] = (nck[i - 1][j - 1] + nck[i - 1][j]) % mod;
    }
  }

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, make_pair(-1, -1));
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    lli x = 0;
    for (int i = 0; i < n; ++i) {
      each (j, g[i]) {
        if (i < j) {
          auto p = rec(i, j);
          auto q = rec(j, i);
          lli y = (p.first * q.first) % mod;
          (y *= nck[p.second + q.second][p.second]) %= mod;
          (x += y) %= mod;
        }
      }
    }
    cout << x << endl;
  }

  return 0;
}
