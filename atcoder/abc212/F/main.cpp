// atcoder/acb212/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

constexpr int N = 2 * 1e5 + 5;
namespace doubling {
  constexpr int DEPTH = 60;

  int T[N][DEPTH];
  function<int(int)> fn;

  void build(const int size, function<int(int)> fn_)
  {
    fn = fn_;

    fill(&T[0][0], &T[N - 1][DEPTH], -1);
    for (int i = 0; i < size; ++i) {
      T[i][0] = fn(i);
    }

    for (int i = 1; i < DEPTH; ++i) {
      for (int j = 0; j < size; ++j) {
        T[j][i] = T[T[j][i - 1]][i - 1];
      }
    }

    return ;
  }

  int query(int x, lli ntimes)
  {
    for (int i = DEPTH; 0 <= i; --i) {
      if (ntimes & (1LL << i)) {
        x = T[x][i];
      }
    }
    return x;
  }
}

struct E {
  int src;
  int dst;
  lli s, t;
  int id;
  E(int _src, int _dst, lli _s, lli _t, int _id) : src(_src), dst(_dst), s(_s), t(_t), id(_id) {}
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m, q;
  while (cin >> n >> m >> q) {
    static vec<E> g[N];
    fill(g, g + N, vec<E>());
    vec<E> es;
    for (int i = 0; i < m; ++i) {
      int a, b;
      lli s, t;
      cin >> a >> b >> s >> t;
      --a;
      --b;
      E e(a, b, s, t, es.size());
      g[a].push_back(e);
      es.push_back(e);
    }
    for (int i = 0; i < n; ++i) {
      const lli inf = 1LL << 60;
      E e(i, i, inf, inf, es.size());
      g[i].push_back(e);
      es.push_back(e);
    }
    for (int i = 0; i < N; ++i) {
      sort(g[i].begin(), g[i].end(), [] (auto a, auto b) { return a.s < b.s; });
    }
    auto next_one = [] (E e, lli s) { return e.s < s; };
    function<int(int)> fn = [&] (int x) {
      int src = es[x].src;
      int dst = es[x].dst;
      lli s = es[x].s;
      lli t = es[x].t;
      int id = es[x].id;
      if (s == t) return x;
      auto itr = lower_bound(g[dst].begin(), g[dst].end(), t, next_one);
      return itr->id;
    };
    doubling::build(es.size(), fn);
    for (int _ = 0; _ < q; ++_) {
      lli x, z;
      int y;
      cin >> x >> y >> z;
      --y;
      auto itr = lower_bound(g[y].begin(), g[y].end(), x, next_one);
      int id = itr->id;
      lli small = 0;
      lli large = 1LL << 30;
      while (small + 1 < large) {
        lli mid = (small + large) / 2;
        int p = doubling::query(id, mid);
        if (z < es[p].t) large = mid;
        else small = mid;
      }
      int p = doubling::query(id, small);
      assert(0 <= p && p < es.size());
      if (es[p].src == es[p].dst) {
        cout << es[p].src + 1 << endl;
        continue;
      }
      if (z <= es[p].s) {
        cout << es[p].src + 1 << endl;
        continue;
      }
      if (z <= es[p].t) {
        cout << es[p].src + 1 << ' ' << es[p].dst + 1 << endl;
        continue;
      }

      int w = es[p].dst;
      itr = lower_bound(g[w].begin(), g[w].end(), es[p].t, next_one);
      id = itr->id;
      if (z <= es[id].s) {
        cout << es[p].dst + 1 << endl;
        continue;
      }

      cout << es[id].src + 1 << ' ' << es[id].dst + 1 << endl;
    }
  }

  return 0;
}
