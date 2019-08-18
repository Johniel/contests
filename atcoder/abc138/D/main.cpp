// atcoder/abc138/D/main.cpp
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

const int N = 2 * 1e5 + 5;
lli x[N];
vector<int> g[N];

void rec(int curr, int prev)
{
  if (prev != -1) {
    x[curr] += x[prev];
  }
  each (next, g[curr]) {
    if (next != prev) rec(next, curr);
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  while (cin >> n >> q) {
    fill(x, x + N, 0);
    fill(g, g + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
    }
    for (int i = 0; i < q; ++i) {
      int p, y;
      cin >> p >> y;
      --p;
      x[p] += y;
    }
    rec(0, -1);
    for (int i = 0; i < n; ++i) {
      cout << x[i] << ' ';
    }
    cout << endl;
  }

  return 0;
}
