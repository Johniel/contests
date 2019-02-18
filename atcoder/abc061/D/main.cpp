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
const lli inf = 1LL << 62;

struct E {
  int src, dst;
  lli cost;
};

pair<lli, bool> bellman_ford(vector<E> es, int src, int dst)
{
  lli cost[N];
  fill(cost, cost + N, inf);
  cost[src] = 0;
  for (int i = 0; i < N; ++i) {
    each (e, es) {
      if (cost[e.dst] > cost[e.src] + e.cost) {
        cost[e.dst] = cost[e.src] + e.cost;
        if (i == N - 1 && e.dst == dst) return make_pair(0, false);
      }
    }
  }
  return make_pair(cost[dst], true);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<E> v;
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      v.push_back((E){a - 1, b - 1, -c});
    }
    auto p = bellman_ford(v, 0, n - 1);
    if (!p.second) cout << "inf" << endl;
    else cout << -1 * p.first << endl;
  }

  return 0;
}
