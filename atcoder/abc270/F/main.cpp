// github.com/Johniel/contests
// atcoder/abc270/F/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

class UnionFind {
public:
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
      if(r[a] == r[b]) r[b]++;
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
private:
  vector<int> r, p;
};

const int N = 2 * 1e5 + 5;
vec<lli> x(N);
vec<lli> y(N);

lli fn(bool s, bool t, vec<pair<lli, pair<int, int>>> es, const int n)
{
  UnionFind uf(N);
  lli z = 0;
  each (e, es) {
    int a = e.second.first;
    int b = e.second.second;
    lli c = e.first;
    if (a == N - 1 && !s) continue;
    if (b == N - 1 && !s) continue;
    if (a == N - 2 && !t) continue;
    if (b == N - 2 && !t) continue;
    if (uf.same(a, b)) continue;
    uf.unite(a, b);
    z += c;
  }
  unless (uf.size(0) == n + s + t) {
    return (1LL << 60);
  }
  return z;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    x.resize(n);
    y.resize(n);
    cin >> x >> y;
    const int X = N - 1;
    const int Y = N - 2;
    vec<pair<lli, pair<int, int>>> es;
    for (int i = 0; i < m; ++i) {
      int a, b;
      lli c;
      cin >> a >> b >> c;
      --a;
      --b;
      es.push_back({c, {a, b}});
    }

    for (int i = 0; i < n; ++i) {
      es.push_back({x[i], {i, X}});
      es.push_back({y[i], {i, Y}});
    }

    sort(es.begin(), es.end());
    lli mn = 1LL << 60;
    setmin(mn, fn(0, 0, es, n));
    setmin(mn, fn(0, 1, es, n));
    setmin(mn, fn(1, 0, es, n));
    setmin(mn, fn(1, 1, es, n));
    cout << mn << endl;
  }

  return 0;
}
