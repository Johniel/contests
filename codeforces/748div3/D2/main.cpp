// codeforces/748div3/D2/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <iostream>
#include <cassert>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <complex>
#include <array>

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

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;
    {
      int mn = *min_element(a.begin(), a.end());
      each (i, a) i += mn;
    }
    vec<int> v;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = i + 1; j < a.size(); ++j) {
        int d = abs(a[i] - a[j]);
        if (d) v.push_back(d);
      }
    }
    {
      map<int, int> m;
      int mx = 0;
      each (i, a) setmax(mx, ++m[i]);
      if (n / 2 <= mx) {
        cout << -1 << endl;
        continue;
      }
    }
    vec<lli> u;
    each (i, v) {
      lli x = i;
      for (lli j = 1; j * j <= i; ++j) {
        if (x % j == 0) {
          u.push_back(j);
          u.push_back(x / j);
        }
      }
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    int z = -1;
    each (div, u) {
      UnionFind uf(a.size());
      for (int i = 0; i < a.size(); ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
          int d = abs(a[i] - a[j]);
          if (d) {
            if (d % div == 0) uf.unite(i, j);
          } else {
            uf.unite(i, j);
          }
        }
      }
      int mx = 0;
      for (int i = 0; i < n; ++i) {
        setmax<int>(mx, uf.size(i));
      }
      if (n / 2 <= mx) setmax<int>(z, div);
    }
    cout << z << endl;
  }

  return 0;
}
