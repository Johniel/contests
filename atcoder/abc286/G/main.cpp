// github.com/Johniel/contests
// atcoder/abc286/G/main.cpp

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

struct UnionFind {
  vector<int> r, p;
  UnionFind(int n) {
    r.resize(n, 0);
    p.resize(n, -1);
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return ;
    if (r[a] > r[b]) {
      p[a] += p[b];
      p[b] = a;
    } else {
      p[b] += p[a];
      p[a] = b;
      if (r[a] == r[b]) ++r[b];
    }
    return ;
  }
  int find(int a) {
    return (p[a] < 0) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return -p.at(find(n));
  }
};

const int N = 2 * 1e5 + 3;
vec<int> g[N];
vec<int> h[N];
int deg[N];

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<int>());
    fill(h, h + N, vec<int>());
    vec<pair<int, int>> es;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      es.push_back(make_pair(min(a, b), max(a, b)));
    }
    int k;
    cin >> k;
    vec<int> s(k);
    cin >> s;
    each (i, s) --i;

    UnionFind uf(n);
    for (int i = 0; i < es.size(); ++i) {
      unless (binary_search(s.begin(), s.end(), i)) {
        uf.unite(es[i].first, es[i].second);
      }
    }
    for (int i = 0; i < n; ++i) {
      uf.find(i);
    }

    each (e, es) {
      e.first = uf.find(e.first);
      e.second = uf.find(e.second);
    }

    vec<int> deg(n, 0);
    each (i, s) {
      ++deg[es[i].first];
      ++deg[es[i].second];
    }

    vec<int> v;
    each (i, s) v.push_back(es[i].first), v.push_back(es[i].second);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int e = 0;
    int o = 0;
    each (i, v) {
      if (deg[i] % 2) ++o;
      else ++e;
    }
    cout << (o == 0 || o == 2 ? "Yes" : "No") << endl;
  }
  return 0;
}
