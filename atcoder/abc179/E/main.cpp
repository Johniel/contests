// atcoder/abc179/E/main.cpp
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

const int M = 1e5 + 5;
lli vis[M];
lli n, x, m;

lli B, length;
lli rec(lli curr, int depth)
{
  if (depth == n) return -1;
  if (0 <= vis[curr]) {
    B = vis[curr];
    length = depth - vis[curr];
    return curr;
  }

  vis[curr] = depth;
  return rec((curr * curr) % m, depth + 1);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> n >> x >> m) {
    // cout << endl;
    fill(vis, vis + M, -1);
    B = length = -1;
    lli y = rec(x, 0);

    if (B == -1) {
      lli z = 0;
      for (int i = 0; i < M; ++i) {
        if (vis[i] == -1) continue;
        z += i;
      }
      cout << z << endl;
      continue;
    }

    lli w = (n - B) / length;
    lli r = (n - B) % length;

    lli z = 0;
    lli p = 0;
    lli q = 0;
    for (int i = 0; i < M; ++i) {
      if (vis[i] == -1) continue;

      if (vis[i] < B) z += i;
      else p += i;

      if (B <= vis[i] && vis[i] < B + r) q += i;
    }

    // cout << B << ' ' << length << endl;
    // cout << z << ' ' << p << ' ' << q << endl;
    cout << z + (p * w) + q << endl;
    // break;
  }

  return 0;
}
