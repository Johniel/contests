// codeforces/722div2/C/main.cpp
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

const int N = 1e5 + 3;
vec<int> g[N];

lli mn[N];
lli mx[N];

lli memo[N][2];
lli rec(int curr, int prev, int color)
{
  lli& ret = memo[curr][color];
  if (ret != -1) return ret;

  lli sum = 0;
  each (next, g[curr]) {
    if (next == prev) continue;

    // 0:mn, 1:mx
    if (color == 0) {
      lli a = 0, b = 0;
      {
        a += abs(mn[curr] - mn[next]);
        a += rec(next, curr, color);
      }
      {
        b += abs(mn[curr] - mx[next]);
        b += rec(next, curr, color ^ 1);
      }
      sum += max(a, b);
    } else {
      lli a = 0, b = 0;
      {
        a += abs(mx[curr] - mn[next]);
        a += rec(next, curr, color ^ 1);
      }
      {
        b += abs(mx[curr] - mx[next]);
        b += rec(next, curr, color);
      }
      sum += max(a, b);
    }
  }
  return ret = sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    fill(g, g + n, vec<int>());
    for (int i = 0; i < n; ++i) {
      memo[i][0] = memo[i][1] = -1;
    }
    for (int i = 0; i < n; ++i) {
      cin >> mn[i] >> mx[i];
    }
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    lli x = rec(0, 0, 0);
    lli y = rec(0, 0, 1);
    cout << max(x, y) << endl;
  }

  return 0;
}
