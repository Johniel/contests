// atcoder/abc225/E/main.cpp
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

struct Fraction
{
  long long int p, q;
  Fraction(long long int p_ = 0, long long int q_ = 1) : p(p_), q(q_) {
    // assert(q != 0);
    auto d = __gcd(p, q);
    p /= d;
    q /= d;
  }
  bool operator < (const Fraction &other) const {
    return p * other.q < other.p * q;
  }
  bool operator <= (const Fraction &other) const {
    return p * other.q <= other.p * q;
  }
  bool operator == (const Fraction &other) const {
    return p == other.p && q == other.q;
  }
};
ostream& operator << (ostream& os, const Fraction& f) { os << f.p << '/' << f.q; return os; }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<pair<lli, lli>> v(n);
    cin >> v;
    const int N = 4 * 1e5 + 3;
    static pair<Fraction, Fraction> a[N];
    for (int i = 0; i < v.size(); ++i) {
      Fraction s(v[i].second - 1, v[i].first);
      Fraction t(v[i].second, v[i].first - 1);
      a[i] = make_pair(s, t);
    }

    const int BEGIN = 0;
    const int END = 1;

    vec<pair<int, int>> u;
    for (int i = 0; i < n; ++i) {
      u.push_back(make_pair(i, BEGIN));
      u.push_back(make_pair(i, END));
    }
    sort(u.begin(), u.end(), [] (auto i, auto j) {
      auto p = (i.second == BEGIN) ? a[i.first].first : a[i.first].second;
      auto q = (j.second == BEGIN) ? a[j.first].first : a[j.first].second;
      if (q == p) return i.second > j.second;
      return p < q;
    });
    static int next[N];
    fill(next, next + N, -1);
    for (int i = 0; i < u.size(); ++i) {
      if (u[i].second == END) {
        next[u[i].first] = i;
      }
    }

    static int dp[N];
    fill(dp, dp + N, 0);
    for (int i = 0; i < u.size(); ++i) {
      setmax(dp[i + 1], dp[i]);
      if (u[i].second == BEGIN) {
        int x = next[u[i].first];
        setmax(dp[x], dp[i] + 1);
      }
    }
    cout << *max_element(dp, dp + N) << endl;
  }

  return 0;
}
