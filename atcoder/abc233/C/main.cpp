// atcoder/abc233/C/main.cpp
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

const int N = 1e5 / 2 + 3;
map<lli, lli> memo[N];
vec<lli> a[N];
int n;
lli rec(int curr, lli x)
{
  if (x == 0) return 0;
  if (curr == n) return x == 1;
  if (memo[curr].count(x)) return memo[curr][x];
  lli z = 0;
  each (i, a[curr]) {
    if (x % i == 0) {
      z += rec(curr + 1, x / i);
    }
  }
  return memo[curr][x] = z;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  lli x;
  while (cin >> n >> x) {
    fill(memo, memo + N, map<lli, lli>());
    fill(a, a + N, vec<lli>());
    for (int i = 0; i < n; ++i) {
      int l;
      cin >> l;
      a[i].resize(l);
      cin >> a[i];
      sort(a[i].begin(), a[i].end());
    }
    cout << rec(0, x) << endl;
  }

  return 0;
}
