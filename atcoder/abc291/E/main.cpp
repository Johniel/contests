// github.com/Johniel/contests
// atcoder/abc291/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

struct E{ int src, dst; };
typedef vector<vector<E>> G;

bool visit(const G &g, int curr, vector<int> &order, vector<int> &color)
{
  constexpr int CLOSED = 1;
  constexpr int VISITED = 2;

  color[curr] = CLOSED;
  each (e, g[curr]) {
    if (color[e.dst] == VISITED) continue;
    if (color[e.dst] == CLOSED) return false;
    if (!visit(g, e.dst, order, color)) return false;
  }
    order.push_back(curr);
  color[curr] = VISITED;
  return true;
}

// verified Codeforces Round #847 C
bool toporogical_sort(const G &g, vector<int> &order)
{
  const int size = g.size();
  vec<int> color(size, 0);
  for (int i = 0; i < size; ++i) {
    if (!color[i] && !visit(g, i, order, color)) {
      return false;
    }
  }
  reverse(order.begin(), order.end());
  return true;
}

bool toporogical_sort2(const G &g, vector<int> &order)
{
  const int size = g.size();
  vec<int> color(size, 0);
  for (int i = size - 1; 0 <= i; --i) {
    if (!color[i] && !visit(g, i, order, color)) {
      return false;
    }
  }
  reverse(order.begin(), order.end());
  return true;
}

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) --i.first, --i.second;

    G g1(n);
    each (i, v) {
      g1[i.first].push_back(E{i.first, i.second});
    }
    for (int i = 0; i < n; ++i) {
      sort(g1[i].begin(), g1[i].end(), [] (auto a, auto b) {
        return make_pair(a.src, a.dst) < make_pair(b.src, b.dst);
      });
    }
    vec<int> o1;
    bool f1 = toporogical_sort(g1, o1);

    for (int i = 0; i < n; ++i) {
      reverse(g1[i].begin(), g1[i].end());
    }
    vec<int> o2;
    bool f2 = toporogical_sort2(g1, o2);

    if (f1 && f2 && o1 == o2) {
      cout << "Yes" << endl;
      vec<int> u(n);
      int x = 0;
      each (i, o1) u[i] = x++;
      each (i, u) cout << i + 1 << ' ' ; cout << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
