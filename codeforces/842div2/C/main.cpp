// github.com/Johniel/contests
// codeforces/842div2/C/main.cpp

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

bool fn1(vec<int> a)
{
  const int n = a.size();

  if (n == 1) {
    cout << "YES" << endl;
    cout << "1" << endl;
    cout << "1" << endl;
    return true;
  }

  vec<int> x(n, -1), y(n, -1);
  map<int, int> m;
  for (int i = 0; i < a.size(); ++i) {
    if (m.count(a[i])) {
      y[i] = a[i];
    } else {
      x[i] = a[i];
    }
    ++m[a[i]];
  }

  // if (m.size() == n) {
  //   cout << "YES" << endl;
  //   for (int i = 0; i < n; ++i) cout << i + 1 << ' '; cout << endl;
  //   for (int i = 0; i < n; ++i) cout << i + 1 << ' '; cout << endl;
  //   return true;
  // }

  each (i, m) {
    if (2 < i.second) {
      cout << "NO" << endl;
      return false;
    }
  }

  bool f = true;
  for (int _ = 0; _ < 2; ++_) {
    set<int> vis;
    for (int i = 0; i < n; ++i) vis.insert(i);
    each (i, y) vis.erase(i);
    vec<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(make_pair(x[i], i));
    }
    sort(v.begin(), v.end());
    // cout << "x: " << x << endl;
    // cout << "y: " << y << endl;
    // cout << "opposit: " << v << endl;
    // cout << "cand: " << vis << endl;
    each (i, v) {
      if (i.first == -1) continue;
      if (y[i.second] != -1) continue;
      y[i.second] = *vis.begin();
      vis.erase(y[i.second]);
      if (vis.empty()) break;
    }
    swap(x, y);
  }
  // cout << x << endl << y << endl;
  for (int i = 0; i < x.size(); ++i) {
    f = f && (max(x[i], y[i]) == a[i]);
  }
  unless (f) {
    cout << "NO" << endl;
    return false;
  }
  cout << "YES" << endl;
  each (i, x) cout << i + 1 << ' '; cout << endl;
  each (i, y) cout << i + 1 << ' '; cout << endl;
  return true;
}

bool fn2(vec<int> a)
{
  vec<int> x(a.size()), y(a.size());
  iota(x.begin(), x.end(), 0);
  iota(y.begin(), y.end(), 0);
  sort(x.begin(), x.end());
  do {
    sort(y.begin(), y.end());
    do {
      bool f = true;
      for (int i = 0; i < a.size(); ++i) {
        f = f && (a[i] == max(x[i], y[i]));
      }
      if (f) return true;
    } while (next_permutation(y.begin(), y.end()));
  } while (next_permutation(x.begin(), x.end()));
  return false;
}

int main(int argc, char *argv[])
{
  if (0) {
    for (int a = 0; a < 5; ++a) {
      for (int b = 0; b < 5; ++b) {
        for (int c = 0; c < 5; ++c) {
          for (int d = 0; d < 5; ++d) {
            for (int e = 0; e < 5; ++e) {
              vec<int> v({a, b, c, d, e});
              cout << v << endl;
              assert(fn1(v) == fn2(v));
            }
          }
        }
      }
    }
  }

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;
    each (i, a) --i;
    fn1(a);
  }
  return 0;
}
