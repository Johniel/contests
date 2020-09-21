// atcoder/acl1/A/main.cpp
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int N = 2 * 1e5 + 5;

  int n;
  while (cin >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;
    each (i, v) --i.first, --i.second;

    int no = 0;
    map<int, int> x, y;
    each (i, v) {
      x[i.first] = y[i.second] = no++;
    }

    const vec<pair<int, int>> tmp = v;
    vec<pair<int, int>> u = v;
    sort(v.begin(), v.end());
    sort(u.begin(), u.end(), [] (auto a, auto b) { return a.second < b.second; });

    UnionFind uf(n);

    {
      set<int> vis;
      for (int i = 0; i < v.size(); ++i) {
        vis.insert(v[i].second);

        auto itr = vis.lower_bound(v[i].second);
        if (itr != vis.begin()) {
          --itr;
          uf.unite(y[v[i].second], y[*itr]);
          // cout << y[v[i].second]+1 << "<-lower->" << y[*itr]+1 << endl;
        }
      }
    }
    {
      set<int> vis;
      reverse(v.begin(), v.end());
      for (int i = 0; i < v.size(); ++i) {
        vis.insert(v[i].second);

        auto itr = vis.lower_bound(v[i].second);
        ++itr;
        if (itr != vis.end()) {
          uf.unite(y[v[i].second], y[*itr]);
          // cout << y[v[i].second]+1 << "<-upper->" << y[*itr]+1 << endl;
        }
      }
    }

    {
      set<int> vis;
      for (int i = 0; i < u.size(); ++i) {
        vis.insert(u[i].first);

        auto itr = vis.lower_bound(u[i].first);
        if (itr != vis.begin()) {
          --itr;
          uf.unite(x[u[i].first], x[*itr]);
        }
      }
    }
    {
      set<int> vis;
      reverse(u.begin(), u.end());
      for (int i = 0; i < u.size(); ++i) {
        vis.insert(u[i].first);

        auto itr = vis.lower_bound(u[i].first);
        ++itr;
        if (itr != vis.end()) {
          uf.unite(x[u[i].first], x[*itr]);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << uf.size(y[tmp[i].second]) << endl;
    }
  }

  return 0;
}
