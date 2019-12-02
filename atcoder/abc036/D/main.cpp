// atcoder/abc036/D/main.cpp
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

const int N = 1e5 + 5;
vector<int> g[N];

const lli mod = 1e9 + 7;

const int B = 0;
const int W = 1;
const int C = 2;
lli memo[N][C];
lli rec(int curr, int prev, int prev_color)
{
  lli& ret = memo[curr][prev_color];
  if (ret != -1) return ret;

  lli w = 1;
  lli b = (prev_color == W);
  each (next, g[curr]) {
    if (prev == next) continue;
    (w *= rec(next, curr, W)) %= mod;
    (b *= rec(next, curr, B)) %= mod;
  }
  return ret = (w + b) % mod;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    fill(&memo[0][0], &memo[N - 1][C - 1] + 1, -1);
    cout << rec(0, -1, W) << endl;
  }

  return 0;
}
