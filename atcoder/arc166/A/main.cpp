// github.com/Johniel/contests
// atcoder/arc166/A/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int n;
  str s, t;
  while (cin >> n >> s >> t) {
    vec<str> v, u;
    bool f = true;
    {
      str x, y;
      for (int i = 0; i < t.size(); ++i) {
        if (t[i] == 'C') {
          f = f && (s[i] == 'C');
          v.push_back(x);
          u.push_back(y);
          x.clear();
          y.clear();
        } else {
          x += s[i];
          y += t[i];
        }
      }
      if (x.size()) v.push_back(x);
      if (y.size()) u.push_back(y);
    }
    unless (f) {
      cout << "No" << endl;
      continue;
    }
    // cout << v << endl; cout << u << endl;

    if (v.size() != u.size()) {
      cout << "No" << endl;
      continue;
    }

    f = true;
    for (int i = 0; i < v.size(); ++i) {
      str x = v[i];
      str y = u[i];
      int a = count(y.begin(), y.end(), 'A') - count(x.begin(), x.end(), 'A');
      if (a < 0) f = false;
      for (int j = 0; j < x.size(); ++j) {
        if (x[j] == 'C') {
          if (a) {
            x[j] = 'A';
            --a;
          } else {
            x[j] = 'B';
          }
        }
      }
      // cout << x << ", " << y << endl;
      int p = 0;
      int q = 0;
      for (int j = 0; j < x.size(); ++j) {
        p += (x[j] == 'A');
        q += (y[j] == 'A');
        if (p < q) f = false;
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
