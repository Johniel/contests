// github.com/Johniel/contests
// codeforces/g22/C/main.cpp

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

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 100 + 3;
int memo[2][N][N][2];
int rec(int turn, int even, int odd, int x)
{
  int& ret = memo[turn][even][odd][x];
  if (ret != -1) return ret;
  if (even == 0 && odd == 0) {
    return 0;
  }

  if (turn) {
    if (even && rec(turn ^ 1, even - 1, odd, x) != x) return ret = x^1;
    if (odd  && rec(turn ^ 1, even, odd - 1, x) != x) return ret = x^1;
    return ret = x;
  } else {
    if (even && (rec(turn ^ 1, even - 1, odd, x) + 0) % 2 == x) return ret = x;
    if (odd  && (rec(turn ^ 1, even, odd - 1, x^1) + 1) % 2 == x) return ret = x;
    return ret = x^1;
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;

    int even = 0;
    int odd = 0;
    each (i, a) {
      if (i % 2) ++odd;
      else ++even;
    }
    fill(&memo[0][0][0][0], &memo[2 - 1][N - 1][N - 1][2 - 1] + 1, -1);
    cout << (rec(0, even, odd, 0) ? "Bob" : "Alice") << endl;
  }

  return 0;
}
