// atcoder/abc17173/E/main.cpp
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

  lli n, k;
  while (cin >> n >> k) {
    vec<lli> a(n);
    cin >> a;

    vec<lli> N, P, Z;
    each (i, a) {
      if (i == 0) Z.push_back(0);
      else if (0 < i) P.push_back(i);
      else if (i < 0) N.push_back(i);
    }

    bool positive = (k <= P.size());
    if (!positive) {
      if (k % 2 == 1 && P.size() && k - 1 <= (N.size() - N.size() % 2) + (P.size() - P.size() % 2)) positive = true;
      if (k % 2 == 0 && k <= (N.size() - N.size() % 2) + P.size()) positive = true;
    }

    if (positive) {
      sort(P.begin(), P.end());
      sort(N.begin(), N.end(), [] (auto x, auto y) { return abs(x) < abs(y); });

      lli z = 1;
      if (k % 2) {
        z = P.back();
        P.pop_back();
        --k;
      }

      while (k) {
        if (2 <= P.size() && 2 <= N.size()) {
          lli x = P.back(); P.pop_back();
          lli y = P.back(); P.pop_back();
          lli s = N.back(); N.pop_back();
          lli t = N.back(); N.pop_back();
          if (x * y < s * t) {
            (z *= (s * t) % mod) %= mod;
            P.push_back(x);
            P.push_back(y);
          } else {
            (z *= (x * y) % mod) %= mod;
            N.push_back(s);
            N.push_back(t);
          }
        } else if (2 <= P.size()) {
          lli x = P.back(); P.pop_back();
          lli y = P.back(); P.pop_back();
          (z *= (x * y) % mod) %= mod;
        } else if (2 <= N.size()) {
          lli s = N.back(); N.pop_back();
          lli t = N.back(); N.pop_back();
          (z *= (s * t) % mod) %= mod;
        } else {
          break;
        }
        k -= 2;
      }
      cout << z << endl;
    } else if (Z.size()) {
      cout << 0 << endl;
    } else {
      sort(a.begin(), a.end(), [] (auto x, auto y) { return abs(x) < abs(y); });
      lli x = 1;
      for (int i = 0; i < k; ++i) {
        (x *= a[i]) %= mod;
      }
      cout << (x + mod) % mod << endl;
    }
  }

  return 0;
}
