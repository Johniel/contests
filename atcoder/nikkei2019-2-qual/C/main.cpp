// atcoder/nikkei2019-2-qual/C/main.cpp
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

  int n;
  while (cin >> n) {
    vec<int> a(n), b(n);
    cin >> a >> b;

    vec<int> t;
    for (int i = 0; i < n; ++i) {
      t.push_back(i);
    }
    sort(t.begin(), t.end(), [&] (auto i, auto j) { return b[i] < b[j]; });

    {
      vec<int> tmp = a;
      for (int i = 0; i < a.size(); ++i) {
        a[i] = tmp[t[i]];
      }
    }
    {
      vec<int> tmp = b;
      for (int i = 0; i < b.size(); ++i) {
        b[i] = tmp[t[i]];
      }
    }
    {
      vec<int> c = a;
      sort(c.begin(), c.end());
      bool f = true;
      for (int i = 0; i < c.size(); ++i) {
        f = f && (c[i] <= b[i]);
      }
      unless (f) {
        cout << "No" << endl;
        continue;
      }
    }

    {
      vec<int> c = a;
      sort(c.begin(), c.end());
      bool f = false;
      for (int i = 0; i + 1 < a.size(); ++i) {
        f = f || (c[i + 1] <= b[i]);
      }
      if (f) {
        cout << "Yes" << endl;
        continue;
      }
    }

    {
      sort(t.begin(), t.end(), [&] (auto i, auto j) { return a[i] < a[j]; });
      UnionFind uf(t.size());
      for (int i = 0; i < t.size(); ++i) {
        uf.unite(i, t[i]);
      }
      if (uf.size(0) != n) {
        cout << "Yes" << endl;
        continue;
      }
    }

    cout << "No" << endl;
  }

  return 0;
}
