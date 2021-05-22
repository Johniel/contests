// atcoder/abc202/D/main.cpp
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

const int N = 30 + 1;
lli memo[N][N];
lli rec(int a, int b)
{
  assert(0 <= a && 0 <= b);
  if (a == 0 && b == 0) return 1;
  lli& ret = memo[a][b];
  if (ret != -1) return ret;
  lli x = 0;
  if (a) x += rec(a - 1, b);
  if (b) x += rec(a, b - 1);
  return ret = x;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);

  // cout << rec(2, 2) << endl;
  // cout << rec(1, 2) << endl;

  int a, b;
  lli k;
  while (cin >> a >> b >> k) {
    str s;
    const int n = a + b;
    for (int i = 0; i < n; ++i) {
      if (a == 0) {
        s += 'b';
        continue;
      }
      if (b == 0) {
        s += 'a';
        continue;
      }

      // cout << i << ' ' << make_pair(a, b) << ' ' << rec(a - 1, b) << ' ' << k << endl;
      if (k <= rec(a - 1, b)) {
        --a;
        s += 'a';
      } else {
        k -= rec(a - 1, b);
        --b;
        s += 'b';
      }
    }
    cout << s << endl;
    // cout << k << endl;
    // assert(k == 0);
  }

  return 0;
}
