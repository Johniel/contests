// codeforces/797div3/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n;
  str s;
  while (cin >> n >> s) {
    const int N = 2000 + 3;
    static int g[N];
    for (int i = 0; i < n; ++i) {
      cin >> g[i];
      --g[i];
    }

    static bool vis[N];
    fill(vis, vis + n, false);

    vec<str> v;
    for (int i = 0; i < n; ++i) {
      unless (vis[i]) {
        int j = i;
        str t;
        while (!vis[j]) {
          vis[j] = true;
          t += s[j];
          j = g[j];
        }
        v.push_back(t);
      }
    }

    lli z = 1;
    each (t, v) {
      lli y = 0;
      for (int i = 1; i <= t.size(); ++i) {
        bool f = true;
        for (int k = 0; k < t.size(); ++k) {
          f = f && (t[k] == t[(i + k) % t.size()]);
        }
        if (f) y = __gcd(y, (lli)i);
      }
      if (y) z = z * y / __gcd(z, y);
    }
    cout << z << endl;
  }

  return 0;
}
