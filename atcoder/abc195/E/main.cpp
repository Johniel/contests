// atcoder/abc195/E/main.cpp
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

const int W = 0;
const int L = 1;

str s;
str x;
int n;

const int N = 2 * 1e5 + 5;
const int M = 7;
int memo[N][M];
int rec(int nth, int mod)
{
  int& ret = memo[nth][mod];
  if (ret != -1) return ret;

  if (nth == n) {
    return (mod ? L : W);
  }

  int mn = L;
  int y = (mod * 10 + (s[nth] - '0')) % 7;
  int z = (mod * 10) % 7;
  if (x[nth] == 'A') {
    // setmin(mn, rec(nth + 1, y) ^ 1);
    // setmin(mn, rec(nth + 1, z) ^ 1);
    mn = -1;
    setmax(mn, rec(nth + 1, y));
    setmax(mn, rec(nth + 1, z));
  }
  if (x[nth] == 'T') {
    setmin(mn, rec(nth + 1, y));
    setmin(mn, rec(nth + 1, z));
  }

  // cout << make_pair(nth, mod) << ' ' << mn << endl;
  return memo[nth][mod] = mn;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> n >> s >> x) {
    fill(&memo[0][0], &memo[N - 1][M - 1] + 1, -1);
    cout << (rec(0, 0) ? "Aoki" : "Takahashi") << endl;
    // break;
  }

  return 0;
}
