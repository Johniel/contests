// atcoder/abc133/F/main.cpp
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

namespace LCA {
  int parent[N];

  const int LOG2N = log2(N) + 1;
  int T[N][LOG2N], L[N];

  int addLevel(int node)
  {
    if (L[node] != -1) return L[node];
    else return L[node] = addLevel(parent[node]) + 1;
  }

// ! keep parent[root] = root
  void build(const int &node)
  {
    const int root = 0;
    fill(L, L + node, -1);
    L[root] = 0;
    for (int i = 0; i < node; ++i) {
      L[i] = addLevel(i);
    }

    fill(&T[0][0], &T[N - 1][LOG2N], -1);
    for (int i = 0; i < node; ++i) {
      T[i][0] = parent[i];
    }
    for(int j = 1; (1 << j) < node; ++j){
      for (int i = 0; i < node; ++i) {
        if (T[i][j - 1] != -1) {
          T[i][j] = T[T[i][j - 1]][j - 1];
        }
      }
    }

    return ;
  }

  int query(int a, int b)
  {
    if (L[a] < L[b]) swap(a, b);

    int lg = 1;
    while ((1 << lg) <= L[a]) ++lg;
    --lg;

    for (int i = lg; 0 <= i; --i) {
      if (L[a] - (1 << i) >= L[b]) {
        a = T[a][i];
      }
    }

    if (a == b) return a;
    for (int i = lg; 0 <= i; --i) {
      if (T[a][i] != -1 && T[a][i] != T[b][i]) {
        a = T[a][i];
        b = T[b][i];
      }
    }

    return parent[a];
  }
};

struct E {
  int src, dst;
  int c, w;
};
vector<E> g[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  while (cin >> n >> q) {
    fill(g, g + N, vector<E>());

    for (int i = 0; i < n - 1; ++i) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      --a;
      --b;
      --c;
      g[a].push_back(E{a, b, c, d});
      g[b].push_back(E{b, a, c, d});
    }
    function<void(int, int)> rec1 = [&] (int curr, int prev) {
      LCA::parent[curr] = prev;
      each (e, g[curr]) {
        if (e.dst == prev) continue;
        rec1(e.dst, e.src);
      }
    };
    rec1(0, 0);
    LCA::build(n);

    map<int, vector<int>> m;
    vector<tuple<int, int, int, int>> v;
    while (q--) {
      int x, y, a, b;
      cin >> x >> y >> a >> b;
      --x;
      --a;
      --b;
      m[a].push_back(x);
      m[b].push_back(x);
      m[LCA::query(a, b)].push_back(x);
      v.push_back(make_tuple(x, y, a, b));
    }

    static lli cost[N];
    map<int, lli> color_cnt;
    map<int, lli> color_cost;

    map<pair<int, int>, lli> m1;
    map<pair<int, int>, lli> m2;

    function<void(int, int)> rec2 = [&] (int curr, int prev) {
      each (c, m[curr]) {
        m1[{curr, c}] = color_cnt[c];
        m2[{curr, c}] = color_cost[c];
      }

      each (e, g[curr]) {
        if (e.dst == prev) continue;
        cost[e.dst] = cost[e.src] + e.w;
        ++color_cnt[e.c];
        color_cost[e.c] += e.w;
        rec2(e.dst, e.src);
        --color_cnt[e.c];
        color_cost[e.c] -= e.w;
      }
    };
    cost[0] = 0;
    rec2(0, 0);

    each (i, v) {
      int x, y, a, b;
      tie(x, y, a, b) = i;
      int c = LCA::query(a, b);
      const lli p = cost[a] + cost[b] - cost[c] * 2;
      const lli q = m1[{a, x}] + m1[{b, x}] - m1[{c, x}] * 2;
      const lli r = m2[{a, x}] + m2[{b, x}] - m2[{c, x}] * 2;
      cout << p + q * y - r << endl;
    }
  }

  return 0;
}
