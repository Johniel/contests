// github.com/Johniel/contests
// codeforces/847div3/C/main.cpp

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

using Graph = vector<vector<int>>;

bool visit(const Graph &g, int curr, vector<int> &order, vector<int> &color)
{
  constexpr int CLOSED = 1;
  constexpr int VISITED = 2;
  color[curr] = CLOSED;
  each (next, g[curr]) {
    if (color[next] == VISITED) continue;
    if (color[next] == CLOSED) return false;
    if (!visit(g, next, order, color)) return false;
  }
  order.push_back(curr);
  color[curr] = VISITED;
  return true;
}

// verified Codeforces Round #847 C
bool toporogical_sort(const Graph &g, vector<int> &order)
{
  const int size = g.size();
  vector<int> color(size, 0);
  for (int i = 0; i < size; ++i) {
    if (!color[i] && !visit(g, i, order, color)) {
      return false;
    }
  }
  reverse(order.begin(), order.end());
  return true;
}

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vec<vec<int>> v(n, vec<int>(n - 1));
    cin >> v;
    each (i, v) each (j, i) --j;
    map<pair<int, int>, int> m;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v[i].size(); ++j) {
        for (int k = j + 1; k < v[i].size(); ++k) {
          ++m[make_pair(v[i][j], v[i][k])];
        }
      }
    }

    Graph g(n);
    each (i, m) {
      if (i.second == n - 2) {
        int src = i.first.first;
        int dst = i.first.second;
        g[src].push_back(dst);
      }
    }
    vec<int> ord;
    toporogical_sort(g, ord);
    each (i, ord) cout << i + 1 << ' '; cout << endl;
  }
  return 0;
}
