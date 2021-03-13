// atcoder/abc195/F/main.cpp
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

bool is_prime(ull x)
{
  for (ull i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  ull a, b;
  while (cin >> a >> b) {
    vec<ull> v;
    for (ull i = a; i <= b; ++i) {
      v.push_back(i);
    }

    vec<ull> p;
    for (int i = 2; i <= 72; ++i) {
      if (is_prime(i)) p.push_back(i);
    }

    vec<int> b(v.size(), 0);
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < p.size(); ++j) {
        if (v[i] % p[j] == 0) {
          b[i] |= (1 << j);
        }
      }
    }

    const int N = (1 << 20) + 2;
    static ull dp[2][N];
    fill(&dp[0][0], &dp[2 - 1][N - 1] + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < v.size(); ++i) {
      const int curr = i % 2;
      const int next = (i + 1) % 2;
      for (int bit = 0; bit < (1 << p.size()); ++bit) {
        dp[next][bit] = 0;
      }
      for (int bit = 0; bit < (1 << p.size()); ++bit) {
        dp[next][bit] += dp[curr][bit];
        unless (bit & b[i]) {
          dp[next][bit | b[i]] += dp[curr][bit];
        }
      }
    }
    ull sum = 0;
    for (int i = 0; i < N; ++i) {
      sum += dp[v.size() % 2][i];
    }
    cout << sum << endl;
  }

  return 0;
}
