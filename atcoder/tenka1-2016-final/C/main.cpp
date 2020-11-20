// atcoder/tenka1-2016-final/C/main.cpp
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

  str s;
  int n;
  while (cin >> s >> n) {
    vec<str> v(n);
    vec<lli> w(n);
    cin >> v >> w;

    const int N = 2 * 1e5 + 205;

    map<lli, vec<pair<int, lli>>> m;
    for (int i = 0; i < v.size(); ++i) {
      lli h = 0;
      each (j, v[i]) {
        h = h * 107 + (j - 'a' + 1);
      }
      m[h].push_back(make_pair(v[i].size(), w[i]));
    }

    static lli dp[N];
    fill(dp, dp + N, -1);
    dp[0] = 0;

    for (int i = 0; i < s.size(); ++i) {
      lli h = 0;
      for (int j = 0; j < 200 && i + j < s.size(); ++j) {
        h = h * 107 + (s[i + j] - 'a' + 1);
        if (m.count(h)) {
          each (e, m[h]) {
            setmax(dp[i + e.first], dp[i] + e.second);
          }
        }
      }
      setmax(dp[i + 1], dp[i]);
    }
    cout << dp[s.size()] << endl;
  }

  return 0;
}
