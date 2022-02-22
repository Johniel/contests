// codeforces/e123/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define endl "\n"

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
constexpr lli mod = 998244353;

lli fn(lli n, int p)
{
  if (p == 0) return 1;
  if (p == 1) return n;
  lli m = fn(n, p / 2);
  (m *= m) %= mod;
  if (p % 2) (m *= n) %= mod;
  return m;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int h, w, k, q;
  while (cin >> h >> w >> k >> q) {
    vec<pair<int, int>> v(q);
    cin >> v;
    each (i, v) {
      --i.first;
      --i.second;
    }
    {
      map<int, int> m;
      each (i, v) {
        unless (m.count(i.first)) {
          int tmp = m.size();
          m[i.first] = tmp;
        }
        i.first = m[i.first];
      }
      setmin<int>(h, m.size() + 1);
    }
    {
      map<int, int> m;
      each (i, v) {
        unless (m.count(i.second)) {
          int tmp = m.size();
          m[i.second] = tmp;
        }
        i.second = m[i.second];
      }
      setmin<int>(w, m.size() + 1);
    }

    const int N = 2 * 1e5 + 3;
    static int a[N];
    static int b[N];
    fill(a, a + h, -1);
    fill(b, b + w, -1);
    for (int i = 0; i < v.size(); ++i) {
      a[v[i].first] = i;
      b[v[i].second] = i;
    }

    {
      map<int, int> m;
      each (i, v) ++m[i.first];
      for (int i = 0; i < v.size(); ++i) {
        if (--m[v[i].first] == 0) m.erase(v[i].first);
        if (b[v[i].second] == i && h == m.size()) {
          b[v[i].second] = -1;
        }
      }
    }
    {
      map<int, int> m;
      each (i, v) ++m[i.second];
      for (int i = 0; i < v.size(); ++i) {
        if (--m[v[i].second] == 0) m.erase(v[i].second);
        if (a[v[i].first] == i && w == m.size()) {
          a[v[i].first] = -1;
        }
      }
    }

    set<int> vis;
    for (int i = 0; i < h; ++i) vis.insert(a[i]);
    for (int i = 0; i < w; ++i) vis.insert(b[i]);
    vis.erase(-1);
    cout << fn(k, vis.size()) << endl;
  }

  return 0;
}
