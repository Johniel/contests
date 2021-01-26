// atcoder/arc111/C/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<int> a(n);
    vec<int> b(n);
    vec<int> p(n);
    cin >> a >> b >> p;

    each (i, p) --i;

    bool f = false;
    for (int i = 0; i < n; ++i) {
      if (a[i] <= b[p[i]] && i != p[i]) f = true;
    }
    if (f) {
      cout << -1 << endl;
      continue;
    }

    map<int, int> idx;
    for (int i = 0; i < n; ++i) {
      idx[p[i]] = i;
    }

    vec<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i);
    }
    sort(v.begin(), v.end(), [&] (auto x, auto y) { return a[x] < a[y]; });

    vec<pair<int, int>> u;
    int x = 0;
    each (i, v) {
      if (p[i] != i) {
        int j = idx[i];
        u.push_back(make_pair(i, j));
        swap(idx[p[i]], idx[p[j]]);
        swap(p[i], p[j]);
      }
    }
    cout << u.size() << endl;
    each (i, u) cout << i.first + 1 << ' ' << i.second + 1 << endl;
  }

  return 0;
}
