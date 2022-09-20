// github.com/Johniel/contests
// atcoder/abc269/D/main.cpp

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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;
    int di[] = {-1, -1, 0, 0, +1, +1};
    int dj[] = {-1, 0, -1, +1, 0, +1};
    sort(v.begin(), v.end());
    UnionFind uf(n);
    for (int k = 0; k < v.size(); ++k) {
      for (int d = 0; d < 6; ++d) {
        int ni = v[k].first + di[d];
        int nj = v[k].second + dj[d];
        pair<int, int> p = make_pair(ni, nj);
        auto itr = lower_bound(v.begin() + k + 1, v.end(), p);
        if (itr == v.end()) continue;
        if (*itr == p) {
          uf.unite(k, itr - v.begin());
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      uf.find(i);
    }
    set<int> vis;
    for (int i = 0; i < n; ++i) {
      vis.insert(uf.find(i));
    }
    cout << vis.size() << endl;
  }

  return 0;
}
