// atcoder/abc252/G/main.cpp
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
constexpr lli mod = 998244353;

const int N = 500 + 3;
lli memo[N][N];
vec<int> a;
lli rec(int begin, int end)
{
  lli& ret = memo[begin][end];
  if (ret != -1) return ret;
  if (end < begin) return 0;
  // cout << make_pair(begin, end) << endl;
  if (begin == end) return 1;

  lli z = rec(begin + 1, end);
  // cout << make_pair(begin, end) << ' ' << make_pair(begin + 1, end) << ":" << rec(begin + 1, end) << endl;
  for (int i = begin + 1; i < end; ++i) {
    if (a[begin] < a[i]) {
      z += rec(begin + 1, i) * rec(i, end) % mod;
      // cout << make_pair(begin, end) << ' ' << make_pair(begin + 1, i) << "+" << make_pair(i, end) << " : " << rec(begin + 1, i) << "*" << rec(i, end) << endl;
      z %= mod;
    }
  }
  return ret = z;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    a.resize(n);
    cin >> a;
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << rec(1, a.size()) << endl;
    // break;
  }

  return 0;
}
