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
  constexpr int DEPTH = log2(N) + 2;

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
  int dst;
  lli s, t;
  int id;
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
    vec<vec<lli>> u;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      int a, b;
      lli s, t;
      cin >> a >> b >> s >> t;
      --a;
      --b;
      g[a].push_back((E){b, s, t, cnt});
      u.push_back(vec<int>({a, b, s, t, cnt}));
      ++cnt;
    }
    for (int i = 0; i < n; ++i) {
      sort(g[i].begin(), g[i].end(), [] (auto a, auto b) {
        if (a.s != b.s) return a.s < b.s;
        return a.t < b.t;
      });
    }
    function<int(int)> fn = [&] (int x) {
      if (x == -1) return -1;
      int src = u[x][0];
      int dst = u[x][1];
      lli s = u[x][2];
      lli t = u[x][3];
      int id = u[x][4];
      auto itr = lower_bonud(g[dst].begin(), g[dst].end(), t + 1);
      if (itr == g[dst].end()) return -1;
      return itr->id;
    };
    doubling::build(n, fn);
    for (int _ = 0; _ < q; ++_) {
      lli x, y, z;
      cin >> x >> y >> z;
      --y;
      auto itr = lower_bound(g[y].begin(), g[y].end(), x);
      int id = (*itr).id;
      int small = 0;
      int large = 1 << 29;
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        int p = doubling::query(id, mid);
        if (p == -1) large = mid;
        else {
          if (z < u[p].t) large = mid;
          else small = mid;
        }
      }
      int p = doubling::query(id, small);
      if (u[p].t == z) cout << u[p].dst + 1 << endl;
      else cout << u[p].src + 1 << ' ' << u[p].dst + 1 << endl;
    }
  }

  return 0;
}
