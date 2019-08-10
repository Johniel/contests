// atcoder/abc137/E/main.cpp
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

const int N = 2500 + 10;
const int M = 5000 + 10;

struct E {
  int src, dst;
  lli coin;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, p;
  while (cin >> n >> m >> p) {
    vector<E> es;
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      es.push_back(E{a, b, p - c});
    }

    static lli coin[N];
    fill(coin, coin + N, 1LL << 60);
    coin[0] = 0;
    static bool vis[N];
    fill(vis, vis + N, false);
    vis[0] = true;

    for (int i = 0; i < n; ++i) {
      each (e, es) {
        if (vis[e.src]) {
          setmin(coin[e.dst], coin[e.src] + e.coin);
          vis[e.dst] = true;
        }
      }
    }
    const lli x = coin[n - 1];

    for (int i = n; i < n+n; ++i) {
      each (e, es) {
        if (vis[e.src]) {
          setmin(coin[e.dst], coin[e.src] + e.coin);
          vis[e.dst] = true;
        }
      }
    }
    const lli y = coin[n - 1];

    if (vis[n - 1]) {
      if (x == y) {
        cout << max(0LL, -1 * coin[n - 1]) << endl;
      } else {
        cout << -1 << endl;
      }
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}
